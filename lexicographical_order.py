def processing_individual_letters(string: str) -> int:
    s = []
    for x in string.lower():
        code = ord(x)
        if code == 1105:
            s.append(1078)
        elif code > 1077:
            s.append(code + 1)
        else:
            s.append(code)
    return s


# true, если первая строка больше, false, если нет.
def reverse_lexicographical_order(string1: str, string2: str) -> bool:
    array1 = processing_individual_letters(string1)
    array2 = processing_individual_letters(string2)
    if len(array1) > len(array2):
        return True
    elif len(array1) < len(array2):
        return False
    for i in range(len(array1)):
        if array1[i] > array2[i]:
            return True
        elif array1[i] < array2[i]:
            return False


print(reverse_lexicographical_order(input(), input()))
