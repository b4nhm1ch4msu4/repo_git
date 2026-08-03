from unittest import result
import os
import shutil

from textnode import TextNode, TextType
from htmlnode import HTMLNode
from leafnode import LeafNode
from parentnode import ParentNode
from split_text_node import split_nodes_link, split_nodes_image
from block import markdown_to_blocks, block_to_block_type, markdown_to_html_node


def main():
#     md = """
# ```
# This is text that _should_ remain
# the **same** even with inline stuff
# ```
# """
    # root_node = markdown_to_html_node(md)
    # html = root_node.to_html()
    # print(html)
    recursive_copy(source="/home/tienp/repo_git/projects/boot_dev/static_site_gen/static/",dest="/home/tienp/repo_git/projects/boot_dev/static_site_gen/public/")

def recursive_copy(source,dest):
    if not os.path.exists(source):
        print(f"{source} path don't exist, please check your folder.")
        return

    if not os.path.exists(dest):
        print(f"{dest} path don't exist, please check your folder.")
        return

    shutil.rmtree(dest)
    print(f"Remove dir: {dest}")
    
    os.mkdir(dest)
    print(f"Create new folder: {dest}")

    for f in os.listdir(source):
        path = os.path.join(source,f)
        if os.path.isfile(path):
            shutil.copy(path,dest)
            print(f"Copy file {path} to {dest}")
        else:
            recursive_copy(path,dest)

if __name__ == "__main__":
    main()
