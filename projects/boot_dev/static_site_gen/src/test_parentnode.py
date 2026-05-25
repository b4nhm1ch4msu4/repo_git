import unittest

from leafnode import LeafNode
from parentnode import ParentNode


class TestParentNode(unittest.TestCase):
    # ---------- Initialization ----------

    def test_init(self):
        child = LeafNode("span", "Hello")
        node = ParentNode("div", [child], {"class": "container"})

        self.assertEqual(node.tag, "div")
        self.assertEqual(node.children, [child])
        self.assertEqual(node.props, {"class": "container"})
        self.assertIsNone(node.value)

    # ---------- to_html basic ----------

    def test_to_html_single_child(self):
        child = LeafNode("p", "Hello")
        parent = ParentNode("div", [child])

        expected = "<div><p>Hello</p></div>"
        self.assertEqual(parent.to_html(), expected)

    def test_to_html_multiple_children(self):
        child1 = LeafNode("b", "Bold")
        child2 = LeafNode("i", "Italic")
        parent = ParentNode("p", [child1, child2])

        expected = "<p><b>Bold</b><i>Italic</i></p>"
        self.assertEqual(parent.to_html(), expected)

    def test_to_html_with_props(self):
        child = LeafNode("span", "Text")
        parent = ParentNode("div", [child], {"id": "main"})

        expected = '<div id="main"><span>Text</span></div>'
        self.assertEqual(parent.to_html(), expected)

    # ---------- Nested ParentNodes ----------

    def test_nested_parent_nodes(self):
        leaf1 = LeafNode("b", "Bold")
        leaf2 = LeafNode("i", "Italic")
        inner = ParentNode("p", [leaf1, leaf2])
        outer = ParentNode("div", [inner])

        expected = "<div><p><b>Bold</b><i>Italic</i></p></div>"
        self.assertEqual(outer.to_html(), expected)

    # ---------- Error Cases ----------

    def test_to_html_raises_if_tag_none(self):
        child = LeafNode("p", "Hello")
        node = ParentNode(None, [child])

        with self.assertRaises(ValueError):
            node.to_html()

    def test_to_html_raises_if_children_none(self):
        node = ParentNode("div", None)

        with self.assertRaises(ValueError):
            node.to_html()

    # ---------- Edge Cases ----------

    def test_empty_children_list(self):
        parent = ParentNode("div", [])
        expected = "<div></div>"
        self.assertEqual(parent.to_html(), expected)

    def test_to_html_with_children(self):
        child_node = LeafNode("span", "child")
        parent_node = ParentNode("div", [child_node])
        self.assertEqual(parent_node.to_html(), "<div><span>child</span></div>")

    def test_to_html_with_grandchildren(self):
        grandchild_node = LeafNode("b", "grandchild")
        child_node = ParentNode("span", [grandchild_node])
        parent_node = ParentNode("div", [child_node])
        self.assertEqual(
            parent_node.to_html(),
            "<div><span><b>grandchild</b></span></div>",
        )


if __name__ == "__main__":
    unittest.main()
