import unittest
from block import block_to_block_type, BlockType, markdown_to_html_node


class TestBlockToBlockType(unittest.TestCase):
    def test_paragraphs(self):
        md = """
This is **bolded** paragraph
text in a p
tag here

This is another paragraph with _italic_ text and `code` here

"""

        node = markdown_to_html_node(md)
        html = node.to_html()
        self.assertEqual(
            html,
        "<div><p>This is <b>bolded</b> paragraph text in a p tag here</p><p>This is another paragraph with <i>italic</i> text and <code>code</code> here</p></div>",
        )


    def test_codeblock(self):
        md = """
```
This is text that _should_ remain
the **same** even with inline stuff
```
"""

        node = markdown_to_html_node(md)
        html = node.to_html()
        self.assertEqual(
            html,
            "<div><pre><code>This is text that _should_ remain\nthe **same** even with inline stuff\n</code></pre></div>",
        )

    def test_orderlist_block(self):
        md = """
1. example
2. order
3. list
4. test
5. case
"""
        node = markdown_to_html_node(md)
        html = node.to_html()
        self.assertEqual(html,"<div><ol><li>example</li><li>order</li><li>list</li><li>test</li><li>case</li></ol></div>")

    def test_unorderlist_block(self):
        md = """
- example
- order
- list
- test
- case
"""
        node = markdown_to_html_node(md)
        html = node.to_html()
        self.assertEqual(html,"<div><ul><li>example</li><li>order</li><li>list</li><li>test</li><li>case</li></ul></div>")
