from robot.api import TestSuite, ResultWriter
from datetime import datetime
import os

suite_path = './Test-suite_1/TestCase1.robot'
suite = TestSuite.from_file_system(suite_path)

suite_name = os.path.splitext(os.path.basename(suite_path))[0]
today = datetime.now().strftime("%Y%m%d")
output_file = f"{today}_{suite_name}_output.xml"

# Run suite and save to XML
result = suite.run(output=output_file, loglevel="DEBUG")

# Generate report only if any test failed
if result.return_code != 0:
    ResultWriter(output_file).write_results(
        report=f"{today}_{suite_name}_report.html",
        log=f"{today}_{suite_name}_log.html"
    )
    print("❌ Test failed — full report generated.")
else:
    print("✅ All tests passed — only XML created.")
