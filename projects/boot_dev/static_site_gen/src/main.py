from textnode import TextNode, TextType
from htmlnode import HTMLNode


def main():
    example = TextNode(
        "This is some anchor text", TextType.LINK, "https://www.boot.dev"
    )
    print(example)
    html_node = HTMLNode(tag="a",value="click this",children=None,props={"href":"https://www.google.com"})
    html_node_with_child = HTMLNode(tag="div", value="please dont ",children=html_node,props={"class":"div_elem"})
    print(html_node)
    print(html_node_with_child)


if __name__ == "__main__":
    main()
