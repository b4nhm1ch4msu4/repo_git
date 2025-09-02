def decorator_upper(f):
    def wrapper():
        f()
        print("Mike")

    return wrapper


@decorator_upper
def hello():
    print("hello")


hello()
