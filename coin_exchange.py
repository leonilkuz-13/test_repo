name = input().strip()
surname = input().strip()
patronymic = input().strip()

coin1 = len(name)
coin2 = len(surname)
coin3 = len(patronymic) if patronymic else 19

amount = int(input().strip())

coins = sorted([coin1, coin2, coin3], reverse=True)

result = []
remaining = amount

for coin in coins:
    if remaining >= coin:
        count = remaining // coin
        result.extend([coin] * count)
        remaining -= coin * count

if remaining == 0:
    print(" ".join(map(str, result)))
else:
    print("-42!")
