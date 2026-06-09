from textnode import TextNode, TextType
from extract_markdown import extract_markdown_images, extract_markdown_links
import re


def split_nodes_delimiter(
    old_nodes: list[TextNode], delimiter: str, text_type: TextType
) -> list[TextNode]:
    new_nodes = []
    for node in old_nodes:
        if node.text_type != TextType.TEXT:
            new_nodes.append(node)
            continue
        if (node.text.count(delimiter) % 2) != 0:
            raise Exception(
                "markdown node is invalid! a matching closing delimiter is not found"
            )
        spliter_list = node.text.split(delimiter)
        new_node = []
        for i in range(len(spliter_list)):
            if (i % 2) == 0:
                new_node.append(TextNode(text=spliter_list[i], text_type=TextType.TEXT))
            else:
                new_node.append(TextNode(text=spliter_list[i], text_type=text_type))
        new_nodes.extend(new_node)
    return new_nodes


def split_nodes_image(old_nodes: list[TextNode]) -> list[TextNode]:
    img_pattern = r"!\[[^\]]+\]\([^)]+\)"
    new_nodes = []
    for node in old_nodes:
        if node.text_type != TextType.TEXT:
            new_nodes.append(node)
            continue
        parts = re.split(f"({img_pattern})", node.text)
        for part in parts:
            if not part:
                continue
            match = re.match(r"!\[([^\]]+)\]\(([^)]+)\)", part)
            if match:
                new_nodes.append(
                    TextNode(
                        text=match.group(1),
                        text_type=TextType.IMAGE,
                        url=match.group(2),
                    )
                )
            else:
                new_nodes.append(TextNode(text=part, text_type=TextType.TEXT))
    return new_nodes


def split_nodes_link(old_nodes: list[TextNode]) -> list[TextNode]:
    link_pattern = r"(?<!!)\[[^\]]+\]\([^)]+\)"
    new_nodes = []
    for node in old_nodes:
        if node.text_type != TextType.TEXT:
            new_nodes.append(node)
            continue
        parts = re.split(f"({link_pattern})", node.text)
        for part in parts:
            if not part:
                continue
            match = re.match(r"(?<!!)\[([^\]]+)\]\(([^)]+)\)", part)
            if match:
                new_nodes.append(
                    TextNode(
                        text=match.group(1), text_type=TextType.LINK, url=match.group(2)
                    )
                )
            else:
                new_nodes.append(TextNode(text=part, text_type=TextType.TEXT))
    return new_nodes


def text_to_textnodes(text):
    text_node = TextNode(text,TextType.TEXT)
    code_split = split_nodes_delimiter(
        old_nodes=[text_node], delimiter="`", text_type=TextType.CODE
    )
    bold_split = split_nodes_delimiter(
        old_nodes=code_split, delimiter="**", text_type=TextType.BOLD
    )
    italic_split = split_nodes_delimiter(
        old_nodes=bold_split, delimiter="_", text_type=TextType.ITATIC
    )
    link_split = split_nodes_link(italic_split)
    image_split = split_nodes_image(link_split)
    return image_split
