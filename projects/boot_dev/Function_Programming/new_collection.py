def new_collection(initial_docs):
    docs_copy = initial_docs.copy()
    def add_doc(doc):
        docs_copy.append(doc)
        return docs_copy
    return add_doc
