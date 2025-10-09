N = int(input())


# функция, которая проверяет, корректно ли ферзь расположен на доске
def correction(lines, collumn, table):
    for line in range(lines):
        if table[line] == collumn or abs(collumn - table[line]) == abs(line - lines):
            return False
    return True


# функция, которая вместе с correction, выверяет корректную перестановку ферзей
def permutation_queen(N):
    def backtrack(line):
        if (
            line == N
        ):  # условие, которое выполняет проверку на полный сбор корректной перестановки.
            result.append(table[:])
            return None
        for collumn in range(N):
            if correction(line, collumn, table):
                table[line] = collumn
                backtrack(line + 1)

    table = (
        [-1] * N
    )  # изначально в массиве хранится N строк, в каждую строку будет записан номер столбца
    result = []
    backtrack(0)
    return len(result)


answer = permutation_queen(N)
print(answer)
