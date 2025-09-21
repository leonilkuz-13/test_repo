array = [-3,12,55,7,1,-19,13,28]
for i in range(len(array) - 1):
    pos = i
    for j in range(pos + 1, len(array)):
        if array[pos] > array[j]:
            pos = j
    if array[pos] != array[i]:
        t = array[pos]
        array[pos] = array[i]
        array[i] = t
print(array)