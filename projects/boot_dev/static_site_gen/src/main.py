from textnode import TextNode, TextType
from leafnode import LeafNode
# from parentnode import ParentNode


def text_node_to_html_node(text_node: TextNode):
    try:
        TextType(text_node.text_type)
    except ValueError:
        raise Exception("Text Type is not valid")
    match text_node.text_type:
        case TextType.TEXT:
            return LeafNode(tag=None, value=text_node.text)
        case TextType.BOLD:
            return LeafNode(tag="b", value=text_node.text)
        case TextType.ITATIC:
            return LeafNode(tag="i", value=text_node.text)
        case TextType.CODE:
            return LeafNode(tag="code", value=text_node.text)
        case TextType.LINK:
            return LeafNode(
                tag="a", value=text_node.text, props={"href": text_node.url}
            )
        case TextType.IMAGE:
            return LeafNode(
                tag="img", value="", props={"src": text_node.url, "alt": text_node.text}
            )


def main():
    example = TextNode(
        "This is some anchor text", TextType.LINK, "https://www.boot.dev"
    )
    print(example)


if __name__ == "__main__":
    main()
