class HTMLNode:
    def __init__(self, tag: str, value: str, children: list, props: dict) -> None:
        self.tag = tag
        self.value = value
        self.children = children
        self.props = props
