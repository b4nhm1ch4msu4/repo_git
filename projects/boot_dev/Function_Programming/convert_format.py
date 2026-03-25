from enum import Enum

DocFormat = Enum("DocFormat", ["PDF", "TXT", "MD", "HTML"])

# don't touch above this line


def convert_format(content, from_format, to_format):
    match(from_format,to_format):
        case (DocFormat.MD,DocFormat.HTML):
            return f"<h1>{content.lstrip('# ')}</h1>"
        case (DocFormat.TXT,DocFormat.PDF):
            return f"[PDF] {content} [PDF]"
        case (DocFormat.HTML,DocFormat.MD):
            return f"# {content.replace('<h1>','').replace('</h1>','')}"
        case _:
            raise Exception("invalid type")
