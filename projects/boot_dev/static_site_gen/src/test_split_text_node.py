import unittest
from textnode import TextNode, TextType
from split_text_node import (
    split_nodes_delimiter,
    split_nodes_image,
    split_nodes_link,
    text_to_textnodes,
)


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

    def test_non_text_node_not_split(self):
        node = TextNode("Bold text", TextType.BOLD)

        result = split_nodes_delimiter([node], "**", TextType.BOLD)
        result_img = split_nodes_image([node])
        result_link = split_nodes_link([node])

        self.assertEqual(result, [node])
        self.assertEqual(result_img, [node])
        self.assertEqual(result_link, [node])

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

    def test_split_images(self):
        node = TextNode(
            "This is text with an ![image](https://i.imgur.com/zjjcJKZ.png) and another ![second image](https://i.imgur.com/3elNhQu.png)",
            TextType.TEXT,
        )
        new_nodes = split_nodes_image([node])
        self.assertListEqual(
            [
                TextNode("This is text with an ", TextType.TEXT),
                TextNode("image", TextType.IMAGE, "https://i.imgur.com/zjjcJKZ.png"),
                TextNode(" and another ", TextType.TEXT),
                TextNode(
                    "second image", TextType.IMAGE, "https://i.imgur.com/3elNhQu.png"
                ),
            ],
            new_nodes,
        )

    def test_single_image(self):
        node = TextNode("Look ![alt](img.png) here", TextType.TEXT)

        result = split_nodes_image([node])

        expected = [
            TextNode("Look ", TextType.TEXT),
            TextNode("alt", TextType.IMAGE, "img.png"),
            TextNode(" here", TextType.TEXT),
        ]

        self.assertEqual(result, expected)

    def test_multiple_images(self):
        node = TextNode("![a](a.png) and ![b](b.jpg)", TextType.TEXT)

        result = split_nodes_image([node])

        expected = [
            TextNode("a", TextType.IMAGE, "a.png"),
            TextNode(" and ", TextType.TEXT),
            TextNode("b", TextType.IMAGE, "b.jpg"),
        ]

        self.assertEqual(result, expected)

    def test_image_at_start(self):
        node = TextNode("![alt](img.png) end", TextType.TEXT)

        result = split_nodes_image([node])

        expected = [
            TextNode("alt", TextType.IMAGE, "img.png"),
            TextNode(" end", TextType.TEXT),
        ]

        self.assertEqual(result, expected)

    def test_image_at_end(self):
        node = TextNode("Start ![alt](img.png)", TextType.TEXT)

        result = split_nodes_image([node])

        expected = [
            TextNode("Start ", TextType.TEXT),
            TextNode("alt", TextType.IMAGE, "img.png"),
        ]

        self.assertEqual(result, expected)

    def test_no_images(self):
        node = TextNode("Just plain text", TextType.TEXT)

        result = split_nodes_image([node])

        self.assertEqual(result, [node])

    # ======================================
    # split_nodes_link tests
    # ======================================

    def test_single_link(self):
        node = TextNode("Click [Google](https://google.com)", TextType.TEXT)

        result = split_nodes_link([node])

        expected = [
            TextNode("Click ", TextType.TEXT),
            TextNode("Google", TextType.LINK, "https://google.com"),
        ]

        self.assertEqual(result, expected)

    def test_multiple_links(self):
        node = TextNode("[One](a.com) and [Two](b.com)", TextType.TEXT)

        result = split_nodes_link([node])

        expected = [
            TextNode("One", TextType.LINK, "a.com"),
            TextNode(" and ", TextType.TEXT),
            TextNode("Two", TextType.LINK, "b.com"),
        ]

        self.assertEqual(result, expected)

    def test_link_at_start(self):
        node = TextNode("[Start](a.com) end", TextType.TEXT)

        result = split_nodes_link([node])

        expected = [
            TextNode("Start", TextType.LINK, "a.com"),
            TextNode(" end", TextType.TEXT),
        ]

        self.assertEqual(result, expected)

    def test_link_at_end(self):
        node = TextNode("Go to [Site](site.com)", TextType.TEXT)

        result = split_nodes_link([node])

        expected = [
            TextNode("Go to ", TextType.TEXT),
            TextNode("Site", TextType.LINK, "site.com"),
        ]

        self.assertEqual(result, expected)

    def test_image_not_treated_as_link(self):
        node = TextNode("![alt](img.png)", TextType.TEXT)

        result = split_nodes_link([node])

        # Should remain plain text because of (?<!!) negative lookbehind
        expected = [TextNode("![alt](img.png)", TextType.TEXT)]

        self.assertEqual(result, expected)

    def test_plain_text(self):
        text = "Just plain text"
        result = text_to_textnodes(text)

        expected = [TextNode("Just plain text", TextType.TEXT)]

        self.assertEqual(result, expected)

    # ---------------------------------
    # Code
    # ---------------------------------

    def test_inline_code(self):
        text = "Use `print()` here"
        result = text_to_textnodes(text)

        expected = [
            TextNode("Use ", TextType.TEXT),
            TextNode("print()", TextType.CODE),
            TextNode(" here", TextType.TEXT),
        ]

        self.assertEqual(result, expected)

    # ---------------------------------
    # Bold
    # ---------------------------------

    def test_bold_text(self):
        text = "This is **bold** text"
        result = text_to_textnodes(text)

        expected = [
            TextNode("This is ", TextType.TEXT),
            TextNode("bold", TextType.BOLD),
            TextNode(" text", TextType.TEXT),
        ]

        self.assertEqual(result, expected)

    # ---------------------------------
    # Italic
    # ---------------------------------

    def test_italic_text(self):
        text = "This is _italic_ text"
        result = text_to_textnodes(text)

        expected = [
            TextNode("This is ", TextType.TEXT),
            TextNode("italic", TextType.ITATIC),
            TextNode(" text", TextType.TEXT),
        ]

        self.assertEqual(result, expected)

    # ---------------------------------
    # Link
    # ---------------------------------

    def test_link(self):
        text = "Click [Google](https://google.com)"
        result = text_to_textnodes(text)

        expected = [
            TextNode("Click ", TextType.TEXT),
            TextNode("Google", TextType.LINK, "https://google.com"),
        ]

        self.assertEqual(result, expected)

    # ---------------------------------
    # Image
    # ---------------------------------

    def test_image(self):
        text = "Look ![cat](cat.png)"
        result = text_to_textnodes(text)

        expected = [
            TextNode("Look ", TextType.TEXT),
            TextNode("cat", TextType.IMAGE, "cat.png"),
        ]

        self.assertEqual(result, expected)

    # ---------------------------------
    # Mixed formatting
    # ---------------------------------

    def test_mixed_formatting(self):
        text = "This is **bold**, _italic_, and `code`"
        result = text_to_textnodes(text)

        expected = [
            TextNode("This is ", TextType.TEXT),
            TextNode("bold", TextType.BOLD),
            TextNode(", ", TextType.TEXT),
            TextNode("italic", TextType.ITATIC),
            TextNode(", and ", TextType.TEXT),
            TextNode("code", TextType.CODE),
        ]

        self.assertEqual(result, expected)

    # ---------------------------------
    # Complex mixed case
    # ---------------------------------

    def test_complex_case(self):
        text = "![img](a.png) **bold** and [link](site.com) with `code`"
        result = text_to_textnodes(text)

        expected = [
            TextNode("img", TextType.IMAGE, "a.png"),
            TextNode(" ", TextType.TEXT),
            TextNode("bold", TextType.BOLD),
            TextNode(" and ", TextType.TEXT),
            TextNode("link", TextType.LINK, "site.com"),
            TextNode(" with ", TextType.TEXT),
            TextNode("code", TextType.CODE),
        ]

        self.assertEqual(result, expected)


if __name__ == "__main__":
    unittest.main()
