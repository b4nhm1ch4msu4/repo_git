from unittest import result
import os
import re
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
    # # Heading 1
    #
    # This is text that _should_ remain
    # the **same** even with inline stuff
    # ```
    # """
    # root_node = markdown_to_html_node(md)
    # html = root_node.to_html()
    # print(html)
    cwd = os.getcwd()
    source_dir = f"{cwd}/static/"
    dest_dir = f"{cwd}/public/"

    shutil.rmtree(dest_dir)
    print(f"Remove dir: {dest_dir}")

    os.mkdir(dest_dir)
    print(f"Create new folder: {dest_dir}")
    recursive_copy(source_dir, dest_dir)
    generate_page(
        f"{cwd}/content/index.md", f"{cwd}/template.html", f"{cwd}/public/index.html"
    )


def recursive_copy(source, dest):
    if not os.path.exists(source):
        print(f"{source} path don't exist, please check your folder.")
        return

    if not os.path.exists(dest):
        print(f"{dest} path don't exist")
        os.mkdir(dest)
        print(f"Create new folder {dest}")


    for f in os.listdir(source):
        path = os.path.join(source, f)
        if os.path.isfile(path):
            shutil.copy(path, dest)
            print(f"Copy file {path} to {dest}")
        else:
            dest_dir = os.path.join(dest,f)
            recursive_copy(path, dest_dir)


def extract_title(markdown):
    title = ""
    match = re.search(r"# (.*)", markdown)
    if match:
        title = match.group(1).strip()
        return title
    else:
        raise Exception("Markdown don't contain a title")


def generate_page(from_path, template_path, dest_path):
    if not os.path.exists(from_path):
        print(f"{from_path} don't exist. Please check source file.")
    if not os.path.exists(template_path):
        print(f"{template_path} don't exist. Please check template file.")

    print(f"Generating page from {from_path} to {dest_path} using {template_path}")
    md = ""
    template = ""
    with open(from_path, "r") as file:
        md = file.read()

    html = markdown_to_html_node(md).to_html()
    title = extract_title(md)

    with open(template_path, "r") as file:
        template = file.read()
    output = template.replace("{{ Title }}", title).replace("{{ Content }}", html)

    dest_dir = os.path.dirname(dest_path)
    if not os.path.exists(dest_dir):
        os.mkdir(dest_dir)

    with open(dest_path, "w") as file:
        file.write(output)


if __name__ == "__main__":
    main()
    # BUG: quote not add new line.
    # BUG: can't get link in list item
    # BUG: can't get bold element from list item
