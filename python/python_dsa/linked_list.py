class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __repr__(self):
        return self.data


class LinkedList:
    def __init__(self):
        self.head = None

    def __repr__(self):
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        nodes.append("None")
        return " -> ".join(nodes)


if __name__ == "__main__":
    llist = LinkedList()
    first_node = Node("1")
    llist.head = first_node
    second_node = Node("2")
    third_node = Node("3")
    first_node.next = second_node
    second_node.next = third_node
    print(llist)
