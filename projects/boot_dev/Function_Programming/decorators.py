# def configure_plugin_decorator(func):
#     def wrapper(*args):
#         args_dict = dict(args)
#         return func(**args_dict)
#     return wrapper

def markdown_to_text_decorator(func):
    def wrapper(*args, **kwargs):
        new_args = list(map(convert_md_to_txt,args))
        kwargs_dict = dict(kwargs)
        new_kwargs = {key:convert_md_to_txt(value) for key,value in kwargs_dict.items()}
        return func(*new_args,**new_kwargs)

    return wrapper

# def markdown_to_text_decorator(func):
#     def wrapper(*args, **kwargs):
#         new_args = [convert_md_to_txt(arg) for arg in args]
#         new_kwargs = {k: convert_md_to_txt(v) for k, v in kwargs.items()}
#         return func(*new_args, **new_kwargs)
#     return wrapper


# don't touch below this line


def convert_md_to_txt(doc):
    lines = doc.split("\n")
    for i in range(len(lines)):
        line = lines[i]
        lines[i] = line.lstrip("# ")
    return "\n".join(lines)

