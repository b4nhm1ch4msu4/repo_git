from queue import Queue

from stack import Stack

from node import Node

# def last_work_experience(work_experiences):
#     if len(work_experiences) == 0:
#         return None
#     return work_experiences[-1]


# class Stack:
#     def __init__(self):
#         self.items = []
#
#     def push(self, item):
#         self.items.append(item)
#
#     def size(self):
#         return len(self.items)
#
#     def peek(self):
#         if len(self.items) > 0:
#             return self.items[-1]
#         return None
#
#     def pop(self):
#         if len(self.items) > 0:
#             last = self.items.pop()
#             return last
#         return None

# class Queue:
#     def __init__(self):
#         self.items = []
#
#     def push(self, item):
#         new_list = [None] * (self.size() + 1)
#         for i in range(self.size()):
#             new_list[i+1] = self.items[i]
#         new_list[0] = item
#         self.items = new_list
#
#     def pop(self):
#         if self.size() > 0:
#             return self.items.pop()
#         return None
#
#     def peek(self):
#         if self.size() > 0:
#             return self.items[-1]
#         return None
#
#     def size(self):
#         return len(self.items)


# def is_balanced(input_str):
#     stack = Stack()
#     for c in input_str:
#         if c == "(":
#             stack.push(c)
#         if c == ")":
#             if stack.size() == 0:
#                 return False
#             stack.pop()
#     if stack.size() == 0:
#         return True
#     return False


# def matchmake(queue: Queue, user):
#     if user[1] == "leave":
#         queue.search_and_remove(user[0])
#     else:
#         queue.push(user[0])
#     if queue.size() >= 4:
#         user1 = queue.pop()
#         user2 = queue.pop()
#         return f"{user1} matched {user2}!"
#     else:
#         return "No match found"


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

    def set_next(self, node):
        self.next = node

    # don't touch below this line

    def __repr__(self):
        return self.val


class LinkedList:
    def __init__(self) -> None:
        self.head = None

    def __iter__(self):
        h_node = self.head
        while(h_node is not None):
            yield h_node
            h_node = h_node.next

    # don't touch below this line

    def __repr__(self) -> str:
        nodes = []
        current = self.head
        while current and hasattr(current, "val"):
            nodes.append(current.val)
            current = current.next
        return " -> ".join(nodes)
