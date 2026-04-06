import os
import subprocess

def run_python_file(working_directory, file_path, args=None):
    try:
        abs_work_path = os.path.abspath(working_directory)
        target_file = os.path.normpath(os.path.join(abs_work_path, file_path))
        valid_target_dir = os.path.commonpath([abs_work_path, target_file]) == abs_work_path
        if not valid_target_dir:
            return f'Error: Cannot execute "{file_path}" as it is outside the permitted working directory'
        if not os.path.isfile(target_file):
            return f'Error: "{file_path}" does not exist or is not a regular file'
        if not target_file.endswith(".py"):
            return f'Error: "{file_path}" is not a Python file'

        command = ["python", target_file]
        if args:
            command.extend(args)
        subprocess.run()
    except Exception as e:
        return f"Error: {e}"
