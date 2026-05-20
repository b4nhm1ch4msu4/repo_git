import unittest

from htmlnode import HTMLNode


class TestHTMLNode(unittest.TestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.header3_node = HTMLNode(
            tag="h3", value="This is header 3", children=None, props=None
        )
        self.link_node = HTMLNode(
            tag="a",
            value=None,
            children=[self.header3_node],
            props={"href": "www.link_node.com", "rel": "stylesheet"},
        )

    def test_props_to_html(self):
        print(self.link_node.props_to_html())

    def test_print_htmlnode(self):
        print(self.link_node)

    def test_eq(self):
        self.assertEqual(self.header3_node.children, None)


if __name__ == "__main__":
    unittest.main()
