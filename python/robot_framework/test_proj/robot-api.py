import os
import re
import sys
import logging
from datetime import datetime
from robot.api import TestSuite, ResultWriter
import argparse

# === Constants ===
STOP_FLAG_FILE = "stop_flag.txt"
LIST_FILE = "list.txt"
LIST_LOOP_FILE = "list_loop.txt"
DEFAULT_REPORT_DIR = "D:\\workspace\\logs\\"
SCRIPTS_DIR = "D:\\workspace\\bmw_icon_script\\Test_Scripts"
VARIABLE_FILE = (
    "D:\\workspace\\bmw_icon_resource\\resource\\VARS\\Node8_Run_Variables.py"
)


# === Logging Setup ===
def setup_log(is_need_logfile: bool):

    # Ensure the log directory exists (optional)
    os.makedirs(".\\logs", exist_ok=True)

    handlers = [logging.StreamHandler(sys.stdout)]

    if is_need_logfile:
        # Create a timestamp for the log file name
        log_time = datetime.now().strftime("%Y%m%d_%H%M%S")
        log_file = f"run_log_{log_time}.txt"
        log_path = os.path.join(".\\logs", log_file)

        handlers.append(logging.FileHandler(log_path, encoding="utf-8"))
        print(f"📁 Logging to file: {log_file}")

    logging.basicConfig(
        level=logging.INFO,
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
        handlers=handlers,
    )


# === Utility Functions ===


def find_test_case(test_id: str, root_dir: str) -> str | None:
    """Find the .robot file matching a given test case ID."""
    if not root_dir:
        root_dir = "."

    pattern = re.compile(rf"{re.escape(test_id)}.*\.robot$", re.IGNORECASE)
    matches = []

    for dir_path, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if pattern.fullmatch(filename):
                matches.append(os.path.join(dir_path, filename))

    if not matches:
        logging.error(f"❌ No test found for ID: {test_id}")
        return None
    if len(matches) > 1:
        logging.warning(f"⚠️ Multiple matches for {test_id}: {matches}")
    return matches[0]


def stop_test_flag(action: str) -> bool:
    """Write or read the stop flag file."""
    if action == "write":
        try:
            with open(STOP_FLAG_FILE, "w", encoding="utf-8") as f:
                f.write("stop")
            print("🛑 Stop flag written to file.")
            return True
        except Exception as e:
            print(f"Failed to write stop flag: {e}")
            return False

    elif action == "read":
        if not os.path.exists(STOP_FLAG_FILE):
            return False
        try:
            with open(STOP_FLAG_FILE, "r", encoding="utf-8") as f:
                flag = f.read().strip()
                return flag.lower() == "stop"
        except Exception as e:
            logging.error(f"Failed to read stop flag: {e}")
            return False

    elif action == "reset":
        print(" 🔃  Reset stop flag ")
        with open(STOP_FLAG_FILE, "w", encoding="utf-8"):
            pass
    else:
        print("Invalid action for stop_test_flag()")
        return False


def run_test_case(suite_path: str, report_dir: str) -> int:
    """Run a single Robot Framework test case."""
    if not suite_path or not os.path.exists(suite_path):
        logging.error(f"❌ Test file not found: {suite_path}")
        return

    suite = TestSuite.from_file_system(suite_path)
    suite_name = os.path.splitext(os.path.basename(suite_path))[0]
    today = datetime.now().strftime("%Y%m%d")

    # Prepare output directories
    output_dir = os.path.join(DEFAULT_REPORT_DIR, report_dir, today)
    os.makedirs(output_dir, exist_ok=True)
    fail_dir = os.path.join(output_dir, "Fail")
    os.makedirs(fail_dir, exist_ok=True)

    output_file = f"{today}_{suite_name}_output.xml"
    output_path = os.path.join(output_dir, output_file)

    # Run the test suite
    logging.info(f"▶️ Running test: {suite_name}")
    result = suite.run(
        output=output_path,
        loglevel="INFO",
        outputdir=output_dir,
        variablefile=VARIABLE_FILE,
        variable=f"workspace:{output_dir}",
    )

    # Generate reports if failed
    if result.return_code != 0:
        log_file = os.path.join(fail_dir, f"{suite_name}_log.html")
        ResultWriter(output_path).write_results(log=log_file, report=None)
        logging.error(f"❌ Test failed — full log generated: {log_file}")
    else:
        logging.info(f"✅ {suite_name} passed — only XML file created.")

    return result.return_code


# === Main Execution Logic ===
def main():
    parser = argparse.ArgumentParser(
        description="Run Robot Framework test cases.")
    parser.add_argument(
        "mode", choices=["debug", "auto", "loop", "stop"], help="Run mode"
    )
    parser.add_argument(
        "test_case_id", nargs="?", help="Test case ID (for debug mode only)"
    )
    parser.add_argument(
        "-m",
        "--max-loops",
        type=int,
        default=10,  # A safe default
        help="Maximum number of iterations for 'loop' mode.",
    )
    args = parser.parse_args()

    mode = args.mode.lower()

    if mode == "debug":
        setup_log(is_need_logfile=False)
        if not args.test_case_id:
            logging.error("❌ Test case ID required in debug mode.")
            sys.exit(1)

        test_file = find_test_case(args.test_case_id, SCRIPTS_DIR)
        if test_file:
            run_test_case(test_file, "debug")

    elif mode == "auto":
        setup_log(is_need_logfile=True)
        stop_test_flag("reset")
        if not os.path.exists(LIST_FILE):
            logging.error(f"❌ Test list file not found: {LIST_FILE}")
            sys.exit(1)

        with open(LIST_FILE, "r", encoding="utf-8") as f:
            list_ids = [line.strip() for line in f if line.strip()]

        for test_id in list_ids:
            test_file = find_test_case(test_id, SCRIPTS_DIR)
            if test_file:
                run_test_case(test_file, "auto")
            if stop_test_flag("read"):
                logging.warning("🛑 Stop flag detected. Stopping execution.")
                return

    elif mode == "stop":
        stop_test_flag("write")

    elif mode == "loop":
        setup_log(is_need_logfile=True)
        stop_test_flag("reset")
        if not os.path.exists(LIST_LOOP_FILE):
            logging.error(f"❌ Test list file not found: {LIST_LOOP_FILE}")
            sys.exit(1)

        with open(LIST_LOOP_FILE, "r", encoding="utf-8") as f:
            list_ids = [line.strip() for line in f if line.strip()]

        iteration = 1
        max_loops = args.max_loops
        while list_ids and iteration <= max_loops:
            failed_ids = []
            logging.info(
                f"--- Starting Loop Iteration {iteration} / {max_loops} ---")
            for test_id in list_ids:
                test_file = find_test_case(test_id, SCRIPTS_DIR)
                if test_file:
                    return_code = run_test_case(test_file, "loop")
                    if return_code != 0:
                        failed_ids.append(test_id)
                if stop_test_flag("read"):
                    logging.warning("Stop flag detected. Stopping execution.")
                    return
            list_ids = failed_ids
            iteration += 1

        if not list_ids:
            logging.info(
                    "🎉 All loop tests passed successfully within the limit!") else:
            logging.warning("All loop tests passed successfully within the limit!")
        else: g(
            )

                f"⚠️ Loop stopped after reaching max iterations ({max_loops})."
            )
f" ❌ The following tests still failed: {failed_ids}")if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("⚠️ Interrupted by user.")
    except Exception as e:
        print(f"Unexpected error: {e}")
        sys.exit(1)
        sys.exit(1)
        sys.exit(1)
        sys.exit(1)
