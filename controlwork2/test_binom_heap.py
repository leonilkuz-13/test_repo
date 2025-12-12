import pytest
from binom_heap import BinomialHeap, Node


class TestBinomialHeap:
    @pytest.mark.parametrize(
        "values,expected_min",
        [
            ([10], 10),
            ([10, 5], 5),
            ([10, 5, 3], 3),
        ],
    )
    def test_insert_and_min(self, values, expected_min):
        heap = BinomialHeap()
        for val in values:
            heap.insert(val)
        assert heap.get_minimum() == expected_min

    @pytest.mark.parametrize(
        "values,expected_order",
        [
            ([10, 5, 3, 8], [3, 5, 8, 10]),
            ([5, 1, 4, 2, 3], [1, 2, 3, 4, 5]),
        ],
    )
    def test_extract_min(self, values, expected_order):
        heap = BinomialHeap()
        for val in values:
            heap.insert(val)
        results = [heap.extract_min() for _ in range(len(values))]
        assert results == expected_order

    def test_empty_heap(self):
        heap = BinomialHeap()
        assert heap.get_minimum() is None
        assert heap.extract_min() is None

    def test_merge(self):
        heap1 = BinomialHeap()
        heap2 = BinomialHeap()
        heap1.insert(5)
        heap1.insert(3)
        heap2.insert(8)
        heap2.insert(2)
        heap1.head = heap1.merge(heap1.head, heap2.head)
        assert heap1.get_minimum() == 2

    @pytest.mark.parametrize(
        "child_key,new_key,expected_root",
        [
            (20, 5, 5),
            (20, 15, 10),
        ],
    )
    def test_decrease_key(self, child_key, new_key, expected_root):
        heap = BinomialHeap()
        parent = Node(10)
        child = Node(child_key)
        parent.child = child
        child.parent = parent
        heap.head = parent
        heap.decrease_key(child, new_key)
        assert heap.head.key == expected_root

    def test_decrease_key_no_increase(self):
        heap = BinomialHeap()
        node = Node(5)
        heap.head = node
        heap.decrease_key(node, 10)
        assert heap.head.key == 5

    def test_delete(self):
        heap = BinomialHeap()
        root = Node(10)
        child = Node(20)
        root.child = child
        child.parent = root
        heap.head = root
        heap.delete(child)
        assert heap.extract_min() == 10
        assert heap.get_minimum() is None
