from os.path import exists
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
    cwd = os.getcwd()
    source_dir = f"{cwd}/static/"
    dest_dir = f"{cwd}/public/"

    if os.path.exists(dest_dir):
        shutil.rmtree(dest_dir)
        print(f"Remove dir: {dest_dir}")

    os.mkdir(dest_dir)
    print(f"Create new folder: {dest_dir}")

    recursive_copy(source_dir, dest_dir)
    # TODO: create generate_recursive function

    generate_page_recursive(f"{cwd}/content", f"{cwd}/template.html", f"{cwd}/public")

    # generate_page(
    #     f"{cwd}/content/index.md", f"{cwd}/template.html", f"{cwd}/public/index.html"
    # )
    # generate_page(
    #     f"{cwd}/content/blog/glorfindel/index.md", f"{cwd}/template.html", f"{cwd}/public/blog/glorfindel/index.html"
    # )
    # generate_page(
    #     f"{cwd}/content/blog/tom/index.md", f"{cwd}/template.html", f"{cwd}/public/blog/tom/index.html"
    # )
    # generate_page(
    #     f"{cwd}/content/blog/majesty/index.md", f"{cwd}/template.html", f"{cwd}/public/blog/majesty/index.html"
    # )
    # generate_page(
    #     f"{cwd}/content/contact/index.md", f"{cwd}/template.html", f"{cwd}/public/contact/index.html"
    # )


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
            dest_dir = os.path.join(dest, f)
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
    # print(html)
    title = extract_title(md)

    with open(template_path, "r") as file:
        template = file.read()
    output = template.replace("{{ Title }}", title).replace("{{ Content }}", html)

    dest_dir = os.path.dirname(dest_path)
    if not os.path.exists(dest_dir):
        os.makedirs(dest_dir, exist_ok=True)

    with open(dest_path, "w") as file:
        file.write(output)


def generate_page_recursive(from_dir, template_path, dest_dir):
    entries_name = os.listdir(from_dir)
    for name in entries_name:
        path = os.path.join(from_dir, name)
        print(f"path: {path}")
        if os.path.isfile(path):
            if path.endswith(".md"):
                dest_path = os.path.join(dest_dir, path.replace(".md", ".html"))
                print(f"dest path: {dest_path}")
                generate_page(path, template_path, dest_path)
        else:
            dest_dir = os.path.join(dest_dir, name)
            generate_page_recursive(path, template_path, dest_dir)
    #BUG: copy from content folder to public folder include content
# Generating page from /home/tienp/Documents/repo_git/projects/boot_dev/static_site_gen/content/index.md to /home/tienp/Documents/r
# epo_git/projects/boot_dev/static_site_gen/content/index.html using /home/tienp/Documents/repo_git/projects/boot_dev/static_site_g
# en/template.html

if __name__ == "__main__":
    main()
    # BUG: quote not add new line.
