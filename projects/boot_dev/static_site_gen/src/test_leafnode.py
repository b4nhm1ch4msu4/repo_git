import unittest
from leafnode import LeafNode

class TestLeafNode(unittest.TestCase):
    def __init__(self, methodName: str = "runTest") -> None:
        super().__init__(methodName)
        self.leaf1 = LeafNode("p", "This is a paragraph of text.")
        self.leaf2 = LeafNode("a", "Click me!", {"href": "https://www.google.com"})

    def test_to_html_func(self):
        print(self.leaf1.to_html())
        print(self.leaf2.to_html())

