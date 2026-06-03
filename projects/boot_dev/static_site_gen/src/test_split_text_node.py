import unittest
from textnode import TextNode, TextType
from split_text_node import split_nodes_delimiter  # adjust import


class TestSplitNodesDelimiter(unittest.TestCase):

    # ---------- BOLD (**) ----------

    def test_split_bold_simple(self):
        node = TextNode("This is **bold** text", TextType.TEXT)
        result = split_nodes_delimiter([node], "**", TextType.BOLD)

        expected = [
            TextNode("This is ", TextType.TEXT),
            TextNode("bold", TextType.BOLD),
            TextNode(" text", TextType.TEXT),
        ]

        self.assertEqual(result, expected)

    def test_split_bold_multiple_sections(self):
        node = TextNode("**bold1** and **bold2**", TextType.TEXT)
        result = split_nodes_delimiter([node], "**", TextType.BOLD)

        expected = [
            TextNode("", TextType.TEXT),
            TextNode("bold1", TextType.BOLD),
            TextNode(" and ", TextType.TEXT),
            TextNode("bold2", TextType.BOLD),
            TextNode("", TextType.TEXT),
        ]

        self.assertEqual(result, expected)

    # ---------- ITALIC (*) ----------

    def test_split_italic(self):
        node = TextNode("This is *italic* text", TextType.TEXT)
        result = split_nodes_delimiter([node], "*", TextType.ITATIC)

        expected = [
            TextNode("This is ", TextType.TEXT),
            TextNode("italic", TextType.ITATIC),
            TextNode(" text", TextType.TEXT),
        ]

        self.assertEqual(result, expected)

    # ---------- CODE (`) ----------

    def test_split_code(self):
        node = TextNode("Use `print()` here", TextType.TEXT)
        result = split_nodes_delimiter([node], "`", TextType.CODE)

        expected = [
            TextNode("Use ", TextType.TEXT),
            TextNode("print()", TextType.CODE),
            TextNode(" here", TextType.TEXT),
        ]

        self.assertEqual(result, expected)

    # ---------- Multiple nodes input ----------

    def test_multiple_nodes_mixed_types(self):
        nodes = [
            TextNode("This is **bold**", TextType.TEXT),
            TextNode("Already bold", TextType.BOLD),
        ]

        result = split_nodes_delimiter(nodes, "**", TextType.BOLD)

        expected = [
            TextNode("This is ", TextType.TEXT),
            TextNode("bold", TextType.BOLD),
            TextNode("", TextType.TEXT),
            TextNode("Already bold", TextType.BOLD),
        ]

        self.assertEqual(result, expected)

    # ---------- Non TEXT nodes should not split ----------

    def test_non_text_node_unchanged(self):
        node = TextNode("Bold text", TextType.BOLD)
        result = split_nodes_delimiter([node], "**", TextType.BOLD)

        self.assertEqual(result, [node])

    # ---------- Unmatched delimiter ----------

    def test_unmatched_delimiter_raises_exception(self):
        node = TextNode("This is **broken bold*", TextType.TEXT)

        with self.assertRaises(Exception):
            split_nodes_delimiter([node], "**", TextType.BOLD)

    # ---------- Empty string ----------

    def test_empty_string(self):
        node = TextNode("", TextType.TEXT)
        result = split_nodes_delimiter([node], "**", TextType.BOLD)

        self.assertEqual(result, [TextNode("", TextType.TEXT)])

    # ---------- Delimiter at edges ----------

    def test_delimiter_at_edges(self):
        node = TextNode("**bold**", TextType.TEXT)
        result = split_nodes_delimiter([node], "**", TextType.BOLD)

        expected = [
            TextNode("", TextType.TEXT),
            TextNode("bold", TextType.BOLD),
            TextNode("", TextType.TEXT),
        ]

        self.assertEqual(result, expected)


if __name__ == "__main__":
    unittest.main()
