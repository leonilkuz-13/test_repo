N = int(input())


# функция, которая проверяет, корректно ли ферзь расположен на доске
def is_valid(lines, column, table):
    for line in range(lines):
        if table[line] == column or abs(column - table[line]) == abs(line - lines):
            return False
    return True


# функция, которая вместе с correction, выверяет корректную перестановку ферзей
def permutation_queen(N):
    def backtrack(line):
        nonlocal count
        if line == N:  # условие, которое выполняет проверку на полный сбор корректной перестановки.
            count += 1
            return None
        for column in range(N):
            if is_valid(line, column, table):
                table[line] = column
                backtrack(line + 1)

    table = [-1] * N  # изначально в массиве хранится N строк, в каждую строку будет записан номер столбца
    count = 0
    backtrack(0)
    return count


answer = permutation_queen(N)
print(answer)
