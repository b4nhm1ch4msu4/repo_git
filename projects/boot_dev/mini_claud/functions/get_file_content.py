import os
from config import MAX_CHARS


def get_file_content(working_directory, file_path):
    try:
        abs_work_path = os.path.abspath(working_directory)
        abs_file_path = os.path.join(abs_work_path, file_path)
        valid_target_dir = os.path.commonpath([abs_work_path, abs_file_path]) == abs_work_path
        if not valid_target_dir:
            print(f'Error: Cannot list "{file_path}" as it is outside the permitted working directory')
            return f'Error: Cannot list "{file_path}" as it is outside the permitted working directory'
        if not os.path.isfile(abs_file_path):
            print(f'Error: "{file_path}" is not a file path')
            return f'Error: "{file_path}" is not a file path'
        with open(abs_file_path,'r') as f:
            file_content = f.read(MAX_CHARS)
            if f.read(1):
                file_content += f'[...File "{f}" truncated at {MAX_CHARS} characters]'
            return file_content
    except Exception as e:
        print(f'Error: {e}') 
        return f'Error: {e}'

