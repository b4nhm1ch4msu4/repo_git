import unittest
from extract_markdown import extract_markdown_images, extract_markdown_links


class TestMarkdownExtraction(unittest.TestCase):
    # ---------- IMAGE TESTS ----------

    def test_extract_single_image(self):
        text = "Here is an image ![alt text](image.png)"
        result = extract_markdown_images(text)

        self.assertEqual(result, [("alt text", "image.png")])

    def test_extract_multiple_images(self):
        text = "![img1](a.png) and ![img2](b.jpg)"
        result = extract_markdown_images(text)

        self.assertEqual(result, [("img1", "a.png"), ("img2", "b.jpg")])

    def test_extract_no_images(self):
        text = "There are no images here"
        result = extract_markdown_images(text)

        self.assertEqual(result, [])

    # ---------- LINK TESTS ----------

    def test_extract_single_link(self):
        text = "Visit [Google](https://google.com)"
        result = extract_markdown_links(text)

        self.assertEqual(result, [("Google", "https://google.com")])

    def test_extract_multiple_links(self):
        text = "[One](a.com) and [Two](b.com)"
        result = extract_markdown_links(text)

        self.assertEqual(result, [("One", "a.com"), ("Two", "b.com")])

    def test_extract_no_links(self):
        text = "No links here!"
        result = extract_markdown_links(text)

        self.assertEqual(result, [])

    # ---------- MIXED CONTENT ----------

    def test_extract_mixed_images_and_links(self):
        text = "![img](img.png) and [link](site.com)"

        images = extract_markdown_images(text)
        links = extract_markdown_links(text)

        self.assertEqual(images, [("img", "img.png")])
        self.assertEqual(links, [("link", "site.com")])

    # ---------- EDGE CASES ----------

    def test_link_with_text_around(self):
        text = "Start [Link](url.com) End"
        result = extract_markdown_links(text)

        self.assertEqual(result, [("Link", "url.com")])

    def test_image_with_text_around(self):
        text = "Start ![Pic](pic.jpg) End"
        result = extract_markdown_images(text)

        self.assertEqual(result, [("Pic", "pic.jpg")])

    def test_broken_markdown_not_matched(self):
        text = "[broken(link.com"
        self.assertEqual(extract_markdown_links(text), [])
        self.assertEqual(extract_markdown_images(text), [])

    # ---------- OTHERS CASES ----------

    def test_extract_markdown_images(self):
        matches = extract_markdown_images(
            "This is text with an ![image](https://i.imgur.com/zjjcJKZ.png)"
        )
        self.assertListEqual([("image", "https://i.imgur.com/zjjcJKZ.png")], matches)


if __name__ == "__main__":
    unittest.main()
