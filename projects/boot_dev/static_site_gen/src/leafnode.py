import json
from htmlnode import HTMLNode


class LeafNode(HTMLNode):
    def __init__(self, tag, value, props=None) -> None:
        super().__init__(tag, value, None, props)

    def to_html(self):
        if self.value is None:
            raise ValueError
        if self.tag is None:
            return self.value
        return f"<{self.tag}{self.props_to_html()}>{self.value}</{self.tag}>"

    def to_dict(self):
        return {"tag": self.tag, "value":self.value, "props":self.props}

    def __repr__(self) -> str:
        return json.dumps(self.to_dict(),indent=2)
