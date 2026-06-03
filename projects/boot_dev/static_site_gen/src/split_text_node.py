from textnode import TextNode, TextType


def split_nodes_delimiter(
    old_nodes: list[TextNode], delimiter: str, text_type: TextType
) -> list[TextNode]:
    new_nodes = []
    for node in old_nodes:
        if node.text_type != TextType.TEXT:
            new_nodes.append(node)
            continue
        if (node.text.count(delimiter) % 2) != 0:
            raise Exception(
                "markdown node is invalid! a matching closing delimiter is not found"
            )
        spliter_list = node.text.split(delimiter)
        new_node = []
        for i in range(len(spliter_list)):
            if (i % 2) == 0:
                new_node.append(TextNode(text=spliter_list[i], text_type=TextType.TEXT))
            else:
                new_node.append(TextNode(text=spliter_list[i], text_type=text_type))
        new_nodes.extend(new_node)
    return new_nodes

def split_nodes_image(old_nodes: list[TextNode]) -> list[TextNode]:
    pass

def split_nodes_link(old_nodes: list[TextNode]) -> list[TextNode]:
    pass
