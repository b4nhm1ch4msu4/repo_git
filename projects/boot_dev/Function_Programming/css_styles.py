import copy


def css_styles(initial_styles):
    styles_copy = copy.deepcopy(initial_styles)

    def add_style(selector, property, value):
        if selector in styles_copy:
            styles_copy[selector].update({property: value})
        else:
            # nonlocal styles_copy
            styles_copy[selector] = {property:value}
        return styles_copy
    return add_style
