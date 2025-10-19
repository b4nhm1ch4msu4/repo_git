import os
import re
import sys
import logging
from datetime import datetime
from robot.api import TestSuite, ResultWriter
import argparse

# === Constants ===
WORKSPACE_DIR = "d:\\workspace"
LOG_BASEDIR = "d:\\logs"
LOG_LEVEL = "INFO"  # TRACE | DEBUG | INFO | WARNING | ERROR
SCRIPTS_DIR = f"{WORKSPACE_DIR}\\bmw_icon_scripts\\Test_Scripts"

STOP_FLAG_FILEPATH = f"{WORKSPACE_DIR}\\stop_flag.txt"
LIST_FILEPATH = f"{WORKSPACE_DIR}\\list.txt"

LOG_FORMAT = "%(asctime)s [%(levelname)s] %(message)s"
DATE_FORMAT = "%Y%m%d"
TIME_FORMAT = "%H:%M:%S"


def log_setup(is_log_to_file: bool = True, log_dir: str = os.path.join(LOG_BASEDIR, "RUN LOG")):

    handlers = [logging.StreamHandler(sys.stdout)]

    if is_log_to_file:
        log_time = datetime.now().strftime(f"{DATE_FORMAT}_{TIME_FORMAT}")
        log_file = f"run_log_{log_time}.txt"
        log_path = os.path.join(log_dir, log_file)
        os.makedirs(log_dir, exist_ok=True)
        handlers.append(logging.FileHandler(log_path, encoding="utf-8"))

    logging.basicConfig(
        level=logging.INFO, format=f"{LOG_FORMAT}", datefmt=f"{TIME_FORMAT}", handlers=handlers
    )


# === Utility Functions ===
def find_test_filepath_by_id(test_id: str, root_dir: str) -> str | None:
    """Find the .robot file matching a given test case ID."""
    if not root_dir:
        root_dir = "."

    test_file_name_pattern = re.compile(
        rf"{re.escape(test_id)}.*\.robot$", re.IGNORECASE
    )
    matches = []

    for dir_path, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if test_file_name_pattern.fullmatch(filename):
                matches.append(os.path.join(dir_path, filename))

    if not matches:
        logging.error(f"❌ No test found for ID: {test_id}")
        return None
    if len(matches) > 1:
        logging.warning(f"⚠️ Multiple matches for {test_id}: {matches}")
    return matches[0]


def stop_test_flag(action: str) -> bool:
    """Write or read the stop flag to file."""
    if action == "write":
        try:
            with open(STOP_FLAG_FILEPATH, "w", encoding="utf-8") as f:
                f.write("stop")
            logging.info("🛑 Stop flag written to file.")
            return True
        except Exception as e:
            logging.error(f"Failed to write stop flag: {e}")
            return False

    elif action == "read":
        if not os.path.exists(STOP_FLAG_FILEPATH):
            return False
        try:
            with open(STOP_FLAG_FILEPATH, "r", encoding="utf-8") as f:
                flag = f.read().strip()
                return flag.lower() == "stop"
        except Exception as e:
            logging.error(f"Failed to read stop flag: {e}")
            return False

    else:
        logging.error("Invalid action for stop_test_flag()")
        return False


def run_test_case(filepath: str, log_dir: str, is_need_pass_log: bool = False):
    """Run a single Robot Framework test case."""
    if not filepath or not os.path.exists(filepath):
        logging.error(f"❌ Test file not found: {filepath}")
        return

    test_suite = TestSuite.from_file_system(filepath)
    test_suite_name = os.path.splitext(os.path.basename(filepath))[0]
    today = datetime.now().strftime(f"{DATE_FORMAT}")

    # Prepare output directories
    output_dir = os.path.join(LOG_BASEDIR, log_dir)
    os.makedirs(output_dir, exist_ok=True)
    fail_dir = os.path.join(output_dir, "FAIL")
    pass_dir = os.path.join(output_dir, "PASS")
    os.makedirs(fail_dir, exist_ok=True)

    output_filename = f"{test_suite_name}_output.xml"
    output_path = os.path.join(output_dir, "OUTPUT", output_filename)

    # Run the test suite
    logging.info(f"▶️ Running test: {test_suite_name}")
    result = test_suite.run(
        output=output_path,
        loglevel=f"{LOG_LEVEL}",
        outputdir=output_dir,
        timestampoutputs=True,
    )

    # Generate reports if failed
    if result.return_code != 0:
        log_html_filepath = os.path.join(
            fail_dir, f"{test_suite_name}_log.html")
        ResultWriter(output_path).write_results(
            log=log_html_filepath, report=None)
        logging.error(
            f"❌ Test failed — full log generated: {
                log_html_filepath}"
        )
        return

    if is_need_pass_log:
        log_html_filepath = os.path.join(
            pass_dir, f"{test_suite_name}_log.html")
        ResultWriter(output_path).write_results(
            log=log_html_filepath, report=None)
        logging.error(
            f"✅ {test_suite_name} passed — full log generated: {
                log_html_filepath}"
        )
    else:
        logging.info(f"✅ {test_suite_name} passed — only XML file created.")


def gen_html_log(output_file: str):
    ResultWriter(output_file).write_results(
        log=log_html_filepath, report=None)


# === Main Execution Logic ===
def main():
    parser = argparse.ArgumentParser(
        description="Run Robot Framework test cases.")
    parser.add_argument(
        "mode", choices=["debug", "auto", "stop"], help="Run mode")
    parser.add_argument(
        "test_case_id", nargs="?", help="Test case ID (for debug mode only)"
    )
    args = parser.parse_args()

    mode = args.mode.lower()

    if mode == "debug":
        if not args.test_case_id:
            logging.warning("❌ Test case ID required in debug mode.")
            sys.exit(1)

        test_filepath = find_test_filepath_by_id(
            args.test_case_id, SCRIPTS_DIR)
        if test_filepath:
            run_test_case(test_filepath, "debug")

    elif mode == "auto":
        if not os.path.exists(LIST_FILEPATH):
            logging.error(f"❌ Test list file not found: {LIST_FILEPATH}")
            sys.exit(1)

        with open(LIST_FILEPATH, "r", encoding="utf-8") as f:
            list_testcases_id = [line.strip() for line in f if line.strip()]

        for testcase_id in list_testcases_id:
            test_filepath = find_test_filepath_by_id(testcase_id, SCRIPTS_DIR)
            if test_filepath:
                run_test_case(test_filepath, "auto")
            if stop_test_flag("read"):
                logging.warning("🛑 Stop flag detected. Stopping execution.")
                return
    elif mode == "loop":

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
