import os
from google.genai import types


def get_files_info(working_directory, directory="."):
    try:
        # print(f"Result for {directory}:")
        if not os.path.isdir(os.path.join(working_directory,directory)):
            # print(f'Error: "{directory}" is not a directory')
            return f'Error: "{directory}" is not a directory'
        abs_work_path = os.path.abspath(working_directory)
        # print(abs_work_path)
        target_dir = os.path.normpath(os.path.join(abs_work_path, directory))
        # print(target_dir)
        valid_target_dir = os.path.commonpath([abs_work_path, target_dir]) == abs_work_path
        # print(valid_target_dir)
        if not valid_target_dir:
            # print(f'Error: Cannot list "{directory}" as it is outside the permitted working directory')
            return f'Error: Cannot list "{directory}" as it is outside the permitted working directory'
        ls_dir = os.listdir(target_dir)
        list_content = []
        for item in ls_dir:
            if os.path.isdir(item):
                list_content.append((item,os.path.getsize(os.path.join(target_dir,item)),True))
            else:
                list_content.append((item,os.path.getsize(os.path.join(target_dir,item)),False))
        # for file in list_content:
            # print(f"{file[0]}: file_size={file[1]}, is_dir={str(file[2])}")
        return list_content
    except Exception as e:
        raise Exception(f"Error: {e}")

schema_get_files_info = types.FunctionDeclaration(
    name="get_files_info",
    description="Lists files in a specified directory relative to the working directory, providing file size and directory status",
    parameters=types.Schema(
        type=types.Type.OBJECT,
        properties={
            "directory": types.Schema(
                type=types.Type.STRING,
                description="Directory path to list files from, relative to the working directory (default is the working directory itself)",
            ),
        },
    ),
)
