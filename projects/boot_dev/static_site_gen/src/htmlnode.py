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
        obj_dict = {}
        obj_dict["tag"] = self.tag if self.tag else None
        obj_dict["value"] = self.value if self.value else None
        if self.children:
            obj_children = []
            for child in self.children:
                obj_children.append(child.to_dict())
            obj_dict["children"] = obj_children
        else:
            obj_dict["children"] = None
        obj_dict["props"] = self.props if self.props else None
        return obj_dict

    def __repr__(self) -> str:
        return json.dumps(self.to_dict(), indent=4)
