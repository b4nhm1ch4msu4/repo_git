import os
from google.genai import types
import subprocess


def run_python_file(working_directory, file_path, args=None):
    try:
        abs_work_path = os.path.abspath(working_directory)
        target_file = os.path.normpath(os.path.join(abs_work_path, file_path))
        valid_target_dir = (
            os.path.commonpath([abs_work_path, target_file]) == abs_work_path
        )
        if not valid_target_dir:
            return f'Error: Cannot execute "{file_path}" as it is outside the permitted working directory'
        if not os.path.isfile(target_file):
            return f'Error: "{file_path}" does not exist or is not a regular file'
        if not target_file.endswith(".py"):
            return f'Error: "{file_path}" is not a Python file'

        command = ["python", file_path]
        if args:
            command.extend(args)
        proc = subprocess.run(
            command, cwd=working_directory, capture_output=True, text=True, timeout=30
        )
        output = ""
        if proc.returncode != 0:
            output = f"Process exited with code {proc.returncode}"
        else:
            if proc.stdout is None or proc.stderr is None:
                output = "No output produced"
            else:
                output = f"STDOUT: {proc.stdout}\nSTDERR: {proc.stderr}"
        return output

    except Exception as e:
        return f"Error: executing Python file: {e}"


schema_run_python_file = types.FunctionDeclaration(
    name="run_python_file",
    description="Run a specified python file relative to the working directory",
    parameters=types.Schema(
        type=types.Type.OBJECT,
        properties={
            "file_path": types.Schema(
                type=types.Type.STRING,
                description="File path to python file which need to exec",
            ),
            "args": types.Schema(
                type=types.Type.ARRAY,
                description="Args to run python file with",
                items=types.Schema(type=types.Type.STRING),
            ),
        },
    ),
)
