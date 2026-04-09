import os
from google.genai import types


def write_file(working_directory, file_path, content):
    try:
        abs_work_path = os.path.abspath(working_directory)
        target_file = os.path.normpath(os.path.join(abs_work_path, file_path))
        valid_target_dir = (
            os.path.commonpath([abs_work_path, target_file]) == abs_work_path
        )
        if not valid_target_dir:
            return f'Error: Cannot write to "{file_path}" as it is outside the permitted working directory'
        if os.path.isdir(target_file):
            return f'Error: Cannot write to "{file_path}" as it is a directory'
        os.makedirs(os.path.dirname(target_file), exist_ok=True)
        with open(target_file, "w") as f:
            f.write(content)
        return (
            f'Successfully wrote to "{file_path}" ({len(content)} characters written)'
        )
    except Exception as e:
        return f"Error: {e}"


schema_write_file = types.FunctionDeclaration(
    name="write_file",
    description="Write content to a file",
    parameters=types.Schema(
        type=types.Type.OBJECT,
        properties={
            "file_path": types.Schema(
                type=types.Type.STRING,
                description="file_path to write content to",
            ),
            "content": types.Schema(
                type=types.Type.STRING, description="Content to write to file"
            ),
        },
        required=["file_path", "content"],
    ),
)
