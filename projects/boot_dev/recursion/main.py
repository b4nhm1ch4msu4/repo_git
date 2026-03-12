def zipmap(keys, values):
    if not len(keys) or not len(values):
        return {}
    # return_dict = zipmap(keys[1:], values[1:])
    # return_dict.update({keys[0]: values[0]})
    # return return_dict
    return zipmap(keys[1:], values[1:]).update({keys[0]: values[0]})
