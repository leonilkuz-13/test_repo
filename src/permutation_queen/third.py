from math import factorial

N = int(input())

def count_permutation(N):
    if N <= 0:
        return None
    return int((factorial(N * N) / (factorial(N) * factorial(N * N - N))))

print(count_permutation(N))