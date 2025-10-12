arr = [2, 7, 1, 9, 8, 23, 42, 72, 34, 55]
n = len(arr)


def heap(arr, n, i):
    largest = i
    left = i * 2 + 1
    right = i * 2 + 2
    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heap(arr, n, largest)


for i in range((n // 2) - 1, -1, -1):
    heap(arr, n - 1, i)

for i in range(n - 1, 0, -1):
    arr[i], arr[0] = arr[0], arr[i]
    heap(arr, i, 0)

print(arr)
