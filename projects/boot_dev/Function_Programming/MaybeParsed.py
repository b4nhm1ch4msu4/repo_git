class MaybeParsed:
    pass


# don't touch above this line


class Parsed(MaybeParsed):
    def __init__(self, doc_name, text):
        self.doc_name = doc_name
        self.text = text


class ParseError(MaybeParsed):
    def __init__(self, doc_name, err):
        self.doc_name = doc_name
        self.err = err
