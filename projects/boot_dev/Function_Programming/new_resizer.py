def new_resizer(max_width, max_height):
    def inner_func(min_width=0, min_height=0):
        if min_width > max_width or min_height > max_height:
            raise Exception("minimum size cannot exceed maximum size")

        def innest_func(width, height):
            if width > max_width:
                width = max_width
            if width < min_width:
                width = min_width
            if height > max_height:
                height = max_height
            if height < min_height:
                height = min_height
            return width, height
        return innest_func
    return inner_func

