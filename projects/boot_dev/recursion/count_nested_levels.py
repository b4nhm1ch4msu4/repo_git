def count_nested_levels(nested_documents, target_document_id, level=1):
    for id in nested_documents:
        if id == target_document_id:
            return level
        nested_level = count_nested_levels(
            nested_documents[id], target_document_id, level=level + 1
        )
        if nested_level != -1:
            return nested_level
    return -1
