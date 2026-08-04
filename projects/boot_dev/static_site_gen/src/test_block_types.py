import unittest
from block import block_to_block_type, BlockType


class TestBlockToBlockType(unittest.TestCase):
    # ---------- HEADING ----------
    def test_heading_valid(self):
        self.assertEqual(block_to_block_type("# Heading"), BlockType.HEADING)
        self.assertEqual(block_to_block_type("###### Heading 6"), BlockType.HEADING)

    def test_heading_invalid(self):
        self.assertEqual(block_to_block_type("#Heading"), BlockType.PARAGRAPH)
        self.assertEqual(block_to_block_type("####### Too many"), BlockType.PARAGRAPH)

    # ---------- CODE ----------
    def test_code_block_valid(self):
        block = "```\nprint('hello')\n```"
        self.assertEqual(block_to_block_type(block), BlockType.CODE)

    def test_code_block_invalid(self):
        block = "```\nprint('hello')"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    # ---------- QUOTE ----------
    def test_quote_valid(self):
        self.assertEqual(block_to_block_type("> quote"), BlockType.QUOTE)
        self.assertEqual(block_to_block_type(">quote"), BlockType.QUOTE)

    def test_quote_multiline(self):
        block = "> line1\n> line2"
        self.assertEqual(block_to_block_type(block), BlockType.QUOTE)

    # ---------- UNORDERED LIST ----------
    def test_unordered_list_valid(self):
        self.assertEqual(block_to_block_type("- item"), BlockType.UNORDERED_LIST)

    def test_unordered_list_invalid(self):
        self.assertEqual(block_to_block_type("* item"), BlockType.PARAGRAPH)

    # ---------- ORDERED LIST ----------
    def test_ordered_list_valid(self):
        self.assertEqual(block_to_block_type("1. item"), BlockType.ORDERED_LIST)
        self.assertEqual(
            block_to_block_type("1. item\n2. next\n3. previous"), BlockType.ORDERED_LIST
        )

    def test_ordered_list_invalid(self):
        self.assertEqual(block_to_block_type("1.item"), BlockType.PARAGRAPH)
        self.assertEqual(block_to_block_type("a. item"), BlockType.PARAGRAPH)

    # ---------- INVALID ORDERED LIST → PARAGRAPH ----------

    def test_not_start_from_1_is_paragraph(self):
        block = "2. first\n3. second\n4. third"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    def test_not_increment_by_1_is_paragraph(self):
        block = "1. first\n3. second\n4. third"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    def test_duplicate_numbers_is_paragraph(self):
        block = "1. first\n2. second\n2. third"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    def test_gap_in_sequence_is_paragraph(self):
        block = "1. first\n2. second\n4. fourth"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    def test_wrong_order_is_paragraph(self):
        block = "1. first\n3. second\n2. third"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    def test_invalid_format_missing_space(self):
        block = "1. first\n2.second\n3. third"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    def test_invalid_format_missing_dot(self):
        block = "1 first\n2. second\n3. third"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    def test_non_numeric_prefix(self):
        block = "a. first\nb. second"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    def test_mixed_invalid_line(self):
        block = "1. first\n2. second\ninvalid line\n3. third"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    def test_single_line_not_start_with_1(self):
        block = "5. only item"
        self.assertEqual(block_to_block_type(block), BlockType.PARAGRAPH)

    # ---------- PARAGRAPH ----------
    def test_paragraph_default(self):
        self.assertEqual(
            block_to_block_type("This is a paragraph"), BlockType.PARAGRAPH
        )


# ---------- RUN ----------
if __name__ == "__main__":
    unittest.main()
