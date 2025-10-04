a = [3, 8, 0, 1, 2, 6, 5, 9, 7]


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


quick_sort(a, 0, len(a) - 1)

print(a)
