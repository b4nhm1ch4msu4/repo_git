def args_logger(*args, **kwargs):
    counter = 1
    for arg in args:
        print(f"{counter}. {arg}")
        counter += 1
    sorted_kwargs = sorted(kwargs.keys())
    for kwarg in sorted_kwargs:
        print(f"* kwarg: {kwargs[kwarg]}")
