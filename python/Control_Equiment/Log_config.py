import logging
import datetime

# Get the current date to use in the log file name
current_date = datetime.datetime.now().strftime("%Y-%m-%d")

log_file_name = f"Logs\\{current_date}_log.txt"

# Configure logging to save logs to a file with the current date in the name
logging.basicConfig(filename=log_file_name, level=logging.INFO,
                    format='%(asctime)s %(filename)-20s %(funcName)-30s %(levelname)-8s Line:%(lineno)-4s %(message)s', 
                    datefmt='%Y-%m-%d %H:%M:%S')
