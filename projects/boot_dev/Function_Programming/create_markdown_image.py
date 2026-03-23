def create_markdown_image(alt_text):
    alt_text = f"![{alt_text}]"
    def add_url(url):
        url = url.replace('(','%28').replace(')','%29')
        final_url = f"{alt_text}({url})"
        def add_title(title=None):
            if not title:
                return final_url
            title = f"\"{title}\""
            final_text = f"{alt_text}({url} {title})"
            return final_text
        return add_title
    return add_url
