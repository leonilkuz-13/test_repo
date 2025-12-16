# функция возвращает -1, если первая строка меньшем, чем вторая, 1, если больше, и 0, если равны
# Г.А не понравилось, обрабатывание отедльного случая с буквой ё, я убрал. передаем строки без ё )))


def reverse_lexicographic_order(string1: str, string2: str) -> int:
    index = 0
    len1 = len(string1)
    len2 = len(string2)

    while index < len1 and index < len2:
        if string1[index] > string2[index]:
            return -1
        elif string1[index] < string2[index]:
            return 1
        index += 1
    if len1 < len2:
        return -1
    elif len1 > len2:
        return 1
    return 0
