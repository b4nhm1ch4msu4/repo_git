import unittest
from leafnode import LeafNode
import json


class TestLeafNode(unittest.TestCase):

    # ---------- Initialization ----------

    def test_init(self):
        node = LeafNode("p", "Hello", {"class": "text"})
        self.assertEqual(node.tag, "p")
        self.assertEqual(node.value, "Hello")
        self.assertIsNone(node.children)
        self.assertEqual(node.props, {"class": "text"})

    # ---------- to_html ----------

    def test_to_html_with_tag_and_props(self):
        node = LeafNode("a", "Click", {"href": "https://example.com"})
        expected = '<a href="https://example.com">Click</a>'
        self.assertEqual(node.to_html(), expected)

    def test_to_html_with_tag_no_props(self):
        node = LeafNode("p", "Paragraph")
        expected = "<p>Paragraph</p>"
        self.assertEqual(node.to_html(), expected)

    def test_to_html_no_tag(self):
        node = LeafNode(None, "Just text")
        self.assertEqual(node.to_html(), "Just text")

    def test_to_html_raises_if_no_value(self):
        node = LeafNode("p", None)
        with self.assertRaises(ValueError):
            node.to_html()

    # ---------- to_dict ----------

    def test_to_dict(self):
        node = LeafNode("span", "Hi", {"style": "color:red"})
        expected = {"tag": "span", "value": "Hi", "props": {"style": "color:red"}}
        self.assertEqual(node.to_dict(), expected)

    # ---------- __repr__ ----------

    def test_repr_returns_valid_json(self):
        node = LeafNode("div", "Content")
        result = repr(node)

        # Ensure it's valid JSON
        parsed = json.loads(result)

        self.assertEqual(parsed["tag"], "div")
        self.assertEqual(parsed["value"], "Content")
        self.assertIn("props", parsed)

    # ---------- Edge Cases ----------

    def test_empty_string_value(self):
        node = LeafNode("p", "")
        self.assertEqual(node.to_html(), "<p></p>")

    def test_props_rendering_multiple(self):
        node = LeafNode("input", "Submit", {"type": "text", "id": "main"})
        html = node.to_html()
        self.assertIn(' type="text"', html)
        self.assertIn(' id="main"', html)

    def test_leaf_to_html_p(self):
        node = LeafNode("p", "Hello, world!")
        self.assertEqual(node.to_html(), "<p>Hello, world!</p>")
