from textnode import TextNode, TextType
from htmlnode import HTMLNode
from leafnode import LeafNode
from parentnode import ParentNode


def main():
    example = TextNode(
        "This is some anchor text", TextType.LINK, "https://www.boot.dev"
    )
    print(example)
    html_node = HTMLNode(tag="a",value="click this",children=None,props={"href":"https://www.google.com"})
    html_node_with_child = HTMLNode(tag="div", value="please dont ",children=[html_node],props={"class":"div_elem"})
    leaf_node = LeafNode(tag="div", value="please dont ",props={"class":"div_elem"})
    # print(html_node)
    # print(html_node_with_child)
    print(leaf_node)
    node = ParentNode(
        "p",
        [
            LeafNode("b", "Bold text"),
            LeafNode(None, "Normal text"),
            LeafNode("i", "italic text"),
            LeafNode(None, "Normal text"),
        ],
    )

    print(node.to_html())

if __name__ == "__main__":
    main()
