from enum import Enum
from typing import List
from parentnode import ParentNode
import re
from textnode import text_node_to_html_node
from htmlnode import HTMLNode
from leafnode import LeafNode
from split_text_node import text_to_textnodes


class BlockType(Enum):
    PARAGRAPH = "paragraph"
    HEADING = "heading"
    CODE = "code"
    QUOTE = "quote"
    UNORDERED_LIST = "unordered_list"
    ORDERED_LIST = "ordered_list"


def block_to_block_type(block: str) -> BlockType:
    heading_pattern = r"^#{1,6}\s.*"
    code_pattern = r"^```\n(.*\n)+```$"
    quote_pattern = r"(>\s?.*)+"
    unordered_pattern = r"(-\s.*)"
    ordered_pattern = r"^\d+\.\s.*"
    if re.match(heading_pattern, block):
        return BlockType.HEADING
    elif re.match(code_pattern, block):
        return BlockType.CODE
    elif re.match(quote_pattern, block):
        return BlockType.QUOTE
    elif re.match(unordered_pattern, block):
        return BlockType.UNORDERED_LIST
    elif re.match(ordered_pattern, block):
        lines = block.splitlines()
        for cur_line in range(len(lines)):
            pattern = rf"^{cur_line+1}\.\s.*"
            if not re.match(pattern, lines[cur_line]):
                return BlockType.PARAGRAPH
        return BlockType.ORDERED_LIST
    else:
        return BlockType.PARAGRAPH


def markdown_to_blocks(markdown: str):
    blocks = markdown.split("\n\n")
    leng = len(blocks)
    for i in range(leng):
        if not blocks[i]:
            blocks.remove(blocks[i])
        else:
            blocks[i] = blocks[i].strip()
    return blocks


def markdown_to_html_node(markdown: str):
    childrent_nodes = list()
    blocks = markdown_to_blocks(markdown)
    for b in blocks:
        b_node = HTMLNode()
        b_type = block_to_block_type(b)
        match b_type:
            case BlockType.PARAGRAPH:
                text_nodes = text_to_textnodes(b)
                html_nodes = []
                for t_node in text_nodes:
                    h_node = text_node_to_html_node(t_node)
                    html_nodes.append(h_node)

                b_node = ParentNode(tag="p", children=html_nodes)
            case BlockType.HEADING:
                h_level = b.count('#')
                b = re.sub(r"#+\s","",b)
                b_node = LeafNode(tag=f"h{h_level}",value=b)
            case BlockType.CODE:
                b = re.sub("```\n","",b)
                b = b.strip("```")
                code_node = LeafNode(tag="code",value=b)
                b_node = ParentNode(tag="pre",children=[code_node])
            case BlockType.QUOTE:
                text = b.replace(">","")
                b_node = LeafNode(tag="blockquote",value=text)
            case BlockType.UNORDERED_LIST:
                lines = b.split("\n")
                li_nodes = []
                for l in lines:
                    l = l.lstrip("- ")
                    nodes = text_to_textnodes(l)
                    childrent = []
                    for n in nodes:
                        childrent.append(text_node_to_html_node(n))
                    i_node = ParentNode(tag="li",children=childrent)
                    li_nodes.append(i_node)
                b_node = ParentNode(tag="ul",children=li_nodes)
            case BlockType.ORDERED_LIST:
                lines = b.split("\n")
                li_nodes = []
                for l in lines:
                    l = re.sub(r"^\d+\.\s","",l)
                    nodes = text_to_textnodes(l)
                    childrent = []
                    for n in nodes:
                        childrent.append(text_node_to_html_node(n))
                    i_node = ParentNode(tag="li",children=childrent)
                    li_nodes.append(i_node)
                b_node = ParentNode(tag="ol",children=li_nodes)
            case _:
                b_node = None
        if b_node is not None:
            childrent_nodes.append(b_node)
    root_node = ParentNode(tag="div",children=childrent_nodes)
    return root_node
