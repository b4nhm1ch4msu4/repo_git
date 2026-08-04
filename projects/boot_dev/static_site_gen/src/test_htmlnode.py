import unittest

from htmlnode import HTMLNode


class TestHTMLNode(unittest.TestCase):
    def test_init(self):
        node = HTMLNode(tag="p", value="Hello", children=None, props={"class": "text"})
        self.assertEqual(node.tag, "p")
        self.assertEqual(node.value, "Hello")
        self.assertIsNone(node.children)
        self.assertEqual(node.props, {"class": "text"})

    def test_props_to_html_with_props(self):
        node = HTMLNode(props={"class": "btn", "id": "main"})
        result = node.props_to_html()
        self.assertIn(' class="btn"', result)
        self.assertIn(' id="main"', result)

    def test_props_to_html_no_props(self):
        node = HTMLNode()
        result = node.props_to_html()
        self.assertEqual(result, "")

    def test_to_dict_without_children(self):
        node = HTMLNode(tag="span", value="Hi", props={"style": "color:red"})
        expected = {
            "tag": "span",
            "value": "Hi",
            "children": None,
            "props": {"style": "color:red"},
        }
        self.assertEqual(node.to_dict(), expected)

    def test_to_dict_with_children(self):
        child1 = HTMLNode(tag="b", value="Bold")
        child2 = HTMLNode(tag="i", value="Italic")
        parent = HTMLNode(tag="p", value=None, children=[child1, child2], props=None)

        result = parent.to_dict()

        self.assertEqual(result["tag"], "p")
        self.assertEqual(len(result["children"]), 2)
        self.assertEqual(result["children"][0]["tag"], "b")
        self.assertEqual(result["children"][1]["tag"], "i")

    def test_repr_returns_json_string(self):
        node = HTMLNode(tag="div", value="Content")
        result = repr(node)

        # Should be valid JSON
        import json

        parsed = json.loads(result)

        self.assertEqual(parsed["tag"], "div")
        self.assertEqual(parsed["value"], "Content")


if __name__ == "__main__":
    unittest.main()
