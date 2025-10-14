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
DEFAULT_REPORT_DIR = r".\output"
SCRIPTS_DIR = r"D:\workspace\bmw_icon_scripts\Test_Scripts"


# === Logging Setup ===
logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(message)s",
    datefmt="%H:%M:%S"
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
            with open(STOP_FLAG_FILE, 'w', encoding='utf-8') as f:
                f.write("stop")
            logging.info("🛑 Stop flag written to file.")
            return True
        except Exception as e:
            logging.error(f"Failed to write stop flag: {e}")
            return False

    elif action == "read":
        if not os.path.exists(STOP_FLAG_FILE):
            return False
        try:
            with open(STOP_FLAG_FILE, 'r', encoding='utf-8') as f:
                flag = f.read().strip()
                return flag.lower() == "stop"
        except Exception as e:
            logging.error(f"Failed to read stop flag: {e}")
            return False

    else:
        logging.error("Invalid action for stop_test_flag()")
        return False


def run_test_case(suite_path: str, report_dir: str = DEFAULT_REPORT_DIR):
    """Run a single Robot Framework test case."""
    if not suite_path or not os.path.exists(suite_path):
        logging.error(f"❌ Test file not found: {suite_path}")
        return

    suite = TestSuite.from_file_system(suite_path)
    suite_name = os.path.splitext(os.path.basename(suite_path))[0]
    today = datetime.now().strftime("%Y%m%d")

    # Prepare output directories
    output_dir = os.path.join(report_dir, today)
    os.makedirs(output_dir, exist_ok=True)
    fail_dir = os.path.join(output_dir, "Fail")
    os.makedirs(fail_dir, exist_ok=True)

    output_file = f"{today}_{suite_name}_output.xml"
    output_path = os.path.join(output_dir, output_file)

    # Run the test suite
    logging.info(f"▶️ Running test: {suite_name}")
    result = suite.run(output=output_path, loglevel="DEBUG",
                       outputdir=output_dir)

    # Generate reports if failed
    if result.return_code != 0:
        log_file = os.path.join(fail_dir, f"{suite_name}_log.html")
        ResultWriter(output_path).write_results(log=log_file, report=None)
        logging.error(f"❌ Test failed — full log generated: {log_file}")
    else:
        logging.info(f"✅ {suite_name} passed — only XML file created.")


# === Main Execution Logic ===
def main():
    parser = argparse.ArgumentParser(
        description="Run Robot Framework test cases.")
    parser.add_argument(
        "mode", choices=["debug", "auto", "stop"], help="Run mode")
    parser.add_argument("test_case_id", nargs="?",
                        help="Test case ID (for debug mode only)")
    args = parser.parse_args()

    mode = args.mode.lower()

    if mode == "debug":
        if not args.test_case_id:
            logging.error("❌ Test case ID required in debug mode.")
            sys.exit(1)

        test_file = find_test_case(args.test_case_id, SCRIPTS_DIR)
        if test_file:
            run_test_case(test_file, r".\debug")

    elif mode == "auto":
        if not os.path.exists(LIST_FILE):
            logging.error(f"❌ Test list file not found: {LIST_FILE}")
            sys.exit(1)

        with open(LIST_FILE, "r", encoding='utf-8') as f:
            list_ids = [line.strip() for line in f if line.strip()]

        for test_id in list_ids:
            test_file = find_test_case(test_id, SCRIPTS_DIR)
            if test_file:
                run_test_case(test_file, r".\auto")
            if stop_test_flag("read"):
                logging.warning("🛑 Stop flag detected. Stopping execution.")
                return

    elif mode == "stop":
        stop_test_flag("write")


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        logging.warning("⚠️ Interrupted by user.")
    except Exception as e:
        logging.exception(f"Unexpected error: {e}")
        sys.exit(1)
