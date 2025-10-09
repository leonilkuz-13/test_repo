array = [30,45,13,44,32,17,28,99]
for i in range(len(array) - 1):
    pos = i
    for j in range(pos + 1,len(array)):
        if array[pos] > array[j]:
            pos = j
    if array[pos] != array[i]:
        t = array[pos]
        array[pos] = array[i]
        array[i] = t
print(array)