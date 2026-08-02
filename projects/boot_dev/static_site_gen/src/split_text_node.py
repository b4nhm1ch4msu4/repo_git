from typing import Text

from textnode import TextNode, TextType
import re


def extract_markdown_images(text):
    return re.findall(r"!\[([^)]+)\]\(([^)]+)\)", text)


def extract_markdown_links(text):
    return re.findall(r"(?<!!)\[([^)]+)\]\(([^)]+)\)", text)


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
    new_nodes = []
    for node in old_nodes:
        if node.text_type != TextType.TEXT:
            new_nodes.append(node)
            continue
        remain_text = node.text
        imgs = extract_markdown_images(remain_text)
        for img in imgs:
            img_section = f"![{img[0]}]({img[1]})"
            sections = remain_text.split(img_section, maxsplit=1)
            if sections[0] != "":
                new_nodes.append(TextNode(sections[0], TextType.TEXT))
            new_nodes.append(TextNode(img[0], TextType.IMAGE, img[1]))
            remain_text = sections[1]
        if remain_text:
            new_nodes.append(TextNode(remain_text, TextType.TEXT))

    return new_nodes


def split_nodes_link(old_nodes: list[TextNode]) -> list[TextNode]:
    new_nodes = []
    for node in old_nodes:
        if node.text_type != TextType.TEXT:
            new_nodes.append(node)
            continue
        remain_text = node.text
        links = extract_markdown_links(remain_text)
        for link in links:
            link_section = f"[{link[0]}]({link[1]})"
            sections = remain_text.split(link_section, maxsplit=1)
            if sections[0] != "":
                new_nodes.append(TextNode(sections[0], TextType.TEXT))
            new_nodes.append(TextNode(link[0], TextType.LINK, link[1]))
            remain_text = sections[1]
        if remain_text:
            new_nodes.append(TextNode(remain_text, TextType.TEXT))

    return new_nodes


def text_to_textnodes(text):
    text_node = TextNode(text, TextType.TEXT)
    new_textnodes = split_nodes_delimiter(
        old_nodes=[text_node], delimiter="`", text_type=TextType.CODE
    )
    new_textnodes = split_nodes_delimiter(
        old_nodes=new_textnodes, delimiter="**", text_type=TextType.BOLD
    )
    new_textnodes = split_nodes_delimiter(
        old_nodes=new_textnodes, delimiter="_", text_type=TextType.ITATIC
    )
    new_textnodes = split_nodes_link(new_textnodes)
    new_textnodes = split_nodes_image(new_textnodes)
    return new_textnodes
