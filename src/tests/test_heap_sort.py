import random

import pytest

from src.homework_in_Python.Heap_sort import heap_sort


def quick_sorted(array):
    array = array.copy()

    def patrittion(nums, low, high):
        pivot = nums[(low + high) // 2]
        i = low - 1
        j = high + 1
        while True:
            i += 1
            while nums[i] < pivot:
                i += 1
            j -= 1
            while nums[j] > pivot:
                j -= 1
            if i >= j:
                return j
            nums[i], nums[j] = nums[j], nums[i]

    def quick_sort(nums, low, high):
        if low < high:
            p = patrittion(nums, low, high)
            quick_sort(nums, low, p)
            quick_sort(nums, p + 1, high)

    quick_sort(array, 0, len(array) - 1)
    return array


def bubble_sort(array):
    array = array.copy()
    n = len(array)
    for i in range(n):
        for j in range(0, n - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    return array


def selection_sort(array):
    array = array.copy()
    n = len(array)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if array[j] < array[min_idx]:
                min_idx = j
        array[i], array[min_idx] = array[min_idx], array[i]
    return array


class TestUnit:
    @pytest.mark.parametrize(
        "input_data,expected",
        [
            ([], []),
            ([1], [1]),
            ([0], [0]),
            ([-1], [-1]),
            ([1, 2], [1, 2]),
            ([2, 1], [1, 2]),
            ([3, 3], [3, 3]),
        ],
    )
    def test_basic_cases(self, input_data, expected):
        result = heap_sort(input_data)
        assert result == expected

    @pytest.mark.parametrize(
        "input_data,expected",
        [
            ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5]),
            ([-5, -3, 0, 1, 2], [-5, -3, 0, 1, 2]),
            ([1, 1, 2, 2, 3], [1, 1, 2, 2, 3]),
        ],
    )
    def test_already_sorted_ascending(self, input_data, expected):
        result = heap_sort(input_data)
        assert result == expected


class TestExtremeCases:
    @pytest.mark.parametrize(
        "input_data,expected",
        [
            ([], []),
            ([1], [1]),
            ([2, 1], [1, 2]),
            ([7, 7, 7], [7, 7, 7]),
            ([0, 0, 0], [0, 0, 0]),
            ([1000, -1000, 1], [-1000, 1, 1000]),
            ([-3, -1, -2], [-3, -2, -1]),
            ([3, -1, 0], [-1, 0, 3]),
            ([3, 1, 2], [1, 2, 3]),
            ([4, 1, 3, 2], [1, 2, 3, 4]),
            ([1, 2, 4, 3, 5], [1, 2, 3, 4, 5]),
            ([3, 1, 3, 2, 1], [1, 1, 2, 3, 3]),
        ],
    )
    def test_all_edge_cases(self, input_data, expected):
        result = heap_sort(input_data)
        assert result == expected


class TestPropertyBased:
    ALGORITHMS = [heap_sort, quick_sorted, bubble_sort, selection_sort, sorted]

    @pytest.mark.parametrize(
        "test_array",
        [
            [],
            [1],
            [1, 2],
            [2, 1],
            [1, 2, 3],
            [3, 2, 1],
            [1, 1, 1],
            [1, 2, 1, 2],
            [-1, -2, -3],
            [1, -1, 2, -2],
            [3, 1, 4, 1, 5, 9, 2, 6],
        ],
    )
    def test_against_other_algorithms(self, test_array):
        heap_result = heap_sort(test_array)
        for algorithm in self.ALGORITHMS:
            if algorithm != heap_sort:
                other_result = algorithm(test_array)
                assert heap_result == other_result

    @pytest.mark.parametrize("array_size", [0, 1, 2, 5, 10, 20, 50])
    def test_random_arrays_different_sizes(self, array_size):
        array = [random.randint(-100, 100) for _ in range(array_size)]
        heap_result = heap_sort(array.copy())
        python_sorted_result = sorted(array)
        assert heap_result == python_sorted_result

    def test_multiple_random_arrays(self):
        for _ in range(100):
            length = random.randint(0, 100)
            array = [random.randint(-1000, 1000) for _ in range(length)]
            heap_result = heap_sort(array.copy())
            expected = sorted(array)
            assert heap_result == expected
