from unittest import result

from textnode import TextNode, TextType
from htmlnode import HTMLNode
from leafnode import LeafNode
from parentnode import ParentNode
from split_text_node import split_nodes_link, split_nodes_image
from block import markdown_to_blocks, block_to_block_type, markdown_to_html_node


def main():
    md = """
## Heading 1

```
print("hello world")
```

> quote
> late than never

This is **bolded** paragraph

This is another paragraph with _italic_ text and `code` here
This is the same paragraph on a new line

"""
    blocks = markdown_to_html_node(md)

if __name__ == "__main__":
    main()
