import unittest
from textnode import TextNode, TextType, text_node_to_html_node
from leafnode import LeafNode


class TestTextType(unittest.TestCase):
    def test_enum_values(self):
        self.assertEqual(TextType.TEXT.value, "text")
        self.assertEqual(TextType.BOLD.value, "bold")
        self.assertEqual(TextType.ITATIC.value, "itatic")
        self.assertEqual(TextType.CODE.value, "code")
        self.assertEqual(TextType.LINK.value, "link")
        self.assertEqual(TextType.IMAGE.value, "image")


class TestTextNode(unittest.TestCase):
    # ---------- Initialization ----------

    def test_init_without_url(self):
        node = TextNode("Hello", TextType.TEXT)

        self.assertEqual(node.text, "Hello")
        self.assertEqual(node.text_type, TextType.TEXT)
        self.assertIsNone(node.url)

    def test_init_with_url(self):
        node = TextNode("Google", TextType.LINK, "https://google.com")

        self.assertEqual(node.text, "Google")
        self.assertEqual(node.text_type, TextType.LINK)
        self.assertEqual(node.url, "https://google.com")

    # ---------- Equality ----------

    def test_equal_nodes(self):
        node1 = TextNode("Hello", TextType.BOLD)
        node2 = TextNode("Hello", TextType.BOLD)

        self.assertEqual(node1, node2)

    def test_not_equal_different_text(self):
        node1 = TextNode("Hello", TextType.TEXT)
        node2 = TextNode("World", TextType.TEXT)

        self.assertNotEqual(node1, node2)

    def test_not_equal_different_type(self):
        node1 = TextNode("Hello", TextType.TEXT)
        node2 = TextNode("Hello", TextType.BOLD)

        self.assertNotEqual(node1, node2)

    def test_not_equal_different_url(self):
        node1 = TextNode("Google", TextType.LINK, "https://google.com")
        node2 = TextNode("Google", TextType.LINK, "https://example.com")

        self.assertNotEqual(node1, node2)

    def test_equal_with_url(self):
        node1 = TextNode("Google", TextType.LINK, "https://google.com")
        node2 = TextNode("Google", TextType.LINK, "https://google.com")

        self.assertEqual(node1, node2)

    # ---------- __repr__ ----------

    def test_repr_output(self):
        node = TextNode("Hello", TextType.CODE)
        expected = "TextNode(Hello, code, None)"
        self.assertEqual(repr(node), expected)

    def test_repr_with_url(self):
        node = TextNode("Google", TextType.LINK, "https://google.com")
        expected = "TextNode(Google, link, https://google.com)"
        self.assertEqual(repr(node), expected)


class TestTextNodeToHtmlNode(unittest.TestCase):
    # ---------- TEXT ----------

    def test_text_type_text(self):
        node = TextNode("Hello", TextType.TEXT)
        html_node = text_node_to_html_node(node)

        self.assertIsInstance(html_node, LeafNode)
        self.assertIsNone(html_node.tag)
        self.assertEqual(html_node.value, "Hello")
        self.assertIsNone(html_node.props)

    # ---------- BOLD ----------

    def test_text_type_bold(self):
        node = TextNode("Bold text", TextType.BOLD)
        html_node = text_node_to_html_node(node)

        self.assertEqual(html_node.tag, "b")
        self.assertEqual(html_node.value, "Bold text")
        self.assertIsNone(html_node.props)

    # ---------- ITALIC ----------

    def test_text_type_italic(self):
        node = TextNode("Italic text", TextType.ITATIC)
        html_node = text_node_to_html_node(node)

        self.assertEqual(html_node.tag, "i")
        self.assertEqual(html_node.value, "Italic text")

    # ---------- CODE ----------

    def test_text_type_code(self):
        node = TextNode("print()", TextType.CODE)
        html_node = text_node_to_html_node(node)

        self.assertEqual(html_node.tag, "code")
        self.assertEqual(html_node.value, "print()")

    # ---------- LINK ----------

    def test_text_type_link(self):
        node = TextNode("Google", TextType.LINK, "https://google.com")
        html_node = text_node_to_html_node(node)

        self.assertEqual(html_node.tag, "a")
        self.assertEqual(html_node.value, "Google")
        self.assertEqual(html_node.props, {"href": "https://google.com"})

    # ---------- IMAGE ----------

    def test_text_type_image(self):
        node = TextNode("Logo", TextType.IMAGE, "logo.png")
        html_node = text_node_to_html_node(node)

        self.assertEqual(html_node.tag, "img")
        self.assertEqual(html_node.value, "")
        self.assertEqual(
            html_node.props,
            {"src": "logo.png", "alt": "Logo"},
        )

    # ---------- INVALID TYPE ----------

    def test_invalid_text_type_raises_exception(self):
        class FakeType:
            pass

        node = TextNode("Hello", FakeType())
        with self.assertRaises(Exception):
            text_node_to_html_node(node)

    def test_text(self):
        node = TextNode("This is a text node", TextType.TEXT)
        html_node = text_node_to_html_node(node)
        self.assertEqual(html_node.tag, None)
        self.assertEqual(html_node.value, "This is a text node")


if __name__ == "__main__":
    unittest.main()
