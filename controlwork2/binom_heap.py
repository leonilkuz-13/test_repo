class Node:
    def __init__(self, key, value=None):
        self.key = key
        self.value = value
        self.degree = 0
        self.child = None
        self.parent = None
        self.sibling = None


class BinomialHeap:
    def __init__(self):
        self.head = None

    def get_minimum(self):
        if self.head is None:
            return None
        min_node = self.head
        current = self.head.sibling
        while current is not None:
            if current.key < min_node.key:
                min_node = current
            current = current.sibling
        return min_node.key

    def merge(self, first_head, second_head):
        if first_head is None:
            return second_head
        if second_head is None:
            return first_head
        if first_head.degree <= second_head.degree:
            merged = first_head
            first_head = first_head.sibling
        else:
            merged = second_head
            second_head = second_head.sibling

        current = merged
        while first_head is not None and second_head is not None:
            if first_head.degree <= second_head.degree:
                current.sibling = first_head
                first_head = first_head.sibling
            else:
                current.sibling = second_head
                second_head = second_head.sibling
            current = current.sibling
        if first_head is not None:
            current.sibling = first_head
        else:
            current.sibling = second_head

        if merged is None:
            return None

        prev = None
        current_node = merged
        next_node = current_node.sibling
        while next_node is not None:
            if current_node.degree != next_node.degree:
                prev = current_node
                current_node = next_node
            elif current_node.key <= next_node.key:
                current_node.sibling = next_node.sibling
                next_node.parent = current_node
                next_node.sibling = current_node.child
                current_node.child = next_node
                current_node.degree += 1
            else:
                if prev is None:
                    merged = next_node
                else:
                    prev.sibling = next_node
                current_node.parent = next_node
                current_node.sibling = next_node.child
                next_node.child = current_node
                next_node.degree += 1
                current_node = next_node
            next_node = current_node.sibling
        return merged

    def insert(self, key, value=None):
        new_node = Node(key, value)
        heap = BinomialHeap()
        heap.head = new_node
        self.head = self.merge(self.head, heap.head)

    def extract_min(self):
        if not self.head:
            return None
        min_node = self.head
        node_before_min = None
        current = self.head
        while current.sibling is not None:
            if current.sibling.key < min_node.key:
                min_node = current.sibling
                node_before_min = current
            current = current.sibling
        if node_before_min is None:
            self.head = min_node.sibling
        else:
            node_before_min.sibling = min_node.sibling
        reversed_children = None
        child = min_node.child
        while child is not None:
            next_child = child.sibling
            child.sibling = reversed_children
            child.parent = None
            reversed_children = child
            child = next_child
        child_heap = BinomialHeap()
        child_heap.head = reversed_children
        self.head = self.merge(self.head, child_heap.head)
        return min_node.key

    def decrease_key(self, node, new_key):
        if new_key > node.key:
            return
        node.key = new_key
        current = node
        parent = node.parent
        while parent is not None and current.key < parent.key:
            current.key, parent.key = parent.key, current.key
            if current.value is not None or parent.value is not None:
                current.value, parent.value = parent.value, current.value

            current = parent
            parent = current.parent

    def delete(self, node):
        current = self.get_minimum()
        if current is None:
            return None
        new_key = current - 1
        self.decrease_key(node, new_key)
        self.extract_min()
