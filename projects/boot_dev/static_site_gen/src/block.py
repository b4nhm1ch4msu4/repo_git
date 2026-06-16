from enum import Enum
import re


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
    for b in blocks:
        if not b:
            blocks.remove(b)
    return blocks

def markdown_to_html_node(markdown: str):
    pass
