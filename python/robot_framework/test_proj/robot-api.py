import sys
import re
from robot.api import TestSuite, ResultWriter
from datetime import datetime
import os


def run_test_case(suite_path, report_dir="./output"):
    suite = TestSuite.from_file_system(suite_path)

    suite_name = os.path.splitext(os.path.basename(suite_path))[0]
    today = datetime.now().strftime("%Y%m%d")
    output_file = f"{today}_{suite_name}_output.xml"
    output_dir = os.path.join(report_dir, today)
    output_path = os.path.join(output_dir, output_file)
    os.makedirs(os.path.join(output_dir, "Fail"), exist_ok=True)
    os.makedirs(output_dir, exist_ok=True)

    # Run suite and save to XML
    result = suite.run(output=output_file, loglevel="DEBUG",
                       outputdir=output_dir)

    # Generate report only if any test failed
    if result.return_code != 0:
        ResultWriter(output_path).write_results(
            log=os.path.join(output_dir, "Fail", f"{suite_name}_log.html"),
            report=None
        )
        print("❌ Test failed — full report generated.")
    else:
        print("✅ All tests passed — only XML created.")


def find_test_case(id: str, root_dir: str) -> str:
    pattern = f"{id}.*\\.robot"
    if not root_dir:
        root_dir = "."
    for dir_path, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if re.fullmatch(pattern, filename):
                return os.path.join(dir_path, filename)


def stop_test_flag(action: str) -> bool:
    if action == "write":
        try:
            with open("stop_flag.txt", 'w') as f:
                f.write("stop")
                print("Write stop flag to flag file!!!")
        except IOError as e:
            # Handle potential errors during file writing
            print(f"An error occurred while writing to the file: {e}")
            return False
        except Exception as e:
            # Handle other unexpected errors
            print(f"An unexpected error occurred: {e}")
            return False
        return True
    elif action == "read":
        if not os.path.exists('stop_flag.txt'):
            return False
        with open('stop_flag.txt', 'r') as f:
            flag = f.read().strip()
            return flag == "stop"
    else:
        print("Invalid action")


def main():
    scripts_dir = r"D:\workspace\bmw_icon_scripts\Test_Scripts"
    mode = sys.argv[1]
    test_case_id = sys.argv[2]
    if mode.lower() == "debug":
        test_file = find_test_case(test_case_id, scripts_dir)
        run_test_case(test_file, "./debug/")
    elif mode.lower() == "auto":
        # run each test case in list file
        with open("list.txt", "r") as f:
            list_ids = [line.strip() for line in f.readlines() if line.strip()]
            for id in list_ids:
                test_file = find_test_case(id, scripts_dir)
                run_test_case(test_file, "./auto/")
                if stop_test_flag("read") is True:
                    return
    elif mode.lower() == "stop":
        stop_test_flag("write")


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(f"❌ Error: {e}")
        sys.exit(1)
