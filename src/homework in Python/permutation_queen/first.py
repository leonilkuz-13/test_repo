from itertools import permutations


N = int(input())


def is_valid(permutation, N):
    for i in range(N):
        for j in range(i + 1, N):
            if abs(permutation[i] - permutation[j]) == abs(i - j):
                return False
    return True


count = 0


for permutation in permutations(range(N)):
    if not is_valid(permutation, N):
        continue
    count += 1

print(count)
