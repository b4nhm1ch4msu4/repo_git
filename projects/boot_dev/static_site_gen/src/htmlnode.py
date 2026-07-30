import json

class HTMLNode:
    def __init__(self, tag=None, value=None, children=None, props=None) -> None:
        self.tag = tag
        self.value = value
        self.children = children
        self.props = props

    def to_html(self):
        raise NotImplementedError

    def props_to_html(self):
        output = ""
        if self.props is not None:
            for key, val in self.props.items():
                output += f' {key}="{val}"'
        return output

    def to_dict(self):
        if self.children:
            return {"tag": self.tag, "value":self.value, "children": [x.to_dict() for x in self.children], "props":self.props}
        return {"tag": self.tag, "value":self.value, "props":self.props}

    def __repr__(self) -> str:
        output = "HTMLnode ("
        if  self.tag:
            output += f" Tag: {self.tag},"
        if self.value:
            output += f" Value: {self.value},"
        if self.children:
            output += f" Children: {self.children},"
        if self.props:
            output += f" Props: {{ {self.props_to_html()} }}"
        output += " )"
        return output
