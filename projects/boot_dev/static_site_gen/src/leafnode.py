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
        obj_dict = {}
        obj_dict["tag"] = self.tag if self.tag else None
        obj_dict["value"] = self.value if self.value else None
        obj_dict["props"] = self.props if self.props else None
        return obj_dict

    def __repr__(self) -> str:
        return json.dumps(self.to_dict(), indent=4)
