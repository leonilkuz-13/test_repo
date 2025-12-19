name = input().strip()
surname = input().strip()
patronymic = input().strip()

coin1 = len(name)
coin2 = len(surname)
coin3 = len(patronymic)

amount = int(input().strip())

max_num1 = amount // coin1 if coin1 > 0 else 0
max_num2 = amount // coin2 if coin2 > 0 else 0
max_num3 = amount // coin3 if coin3 > 0 else 0

flag = False
result = {coin1: 0, coin2: 0, coin3: 0}

for num1 in range(max_num1 + 1):
    for num2 in range(max_num2 + 1):
        for num3 in range(max_num3 + 1):
            if num1 * coin1 + num2 * coin2 + num3 * coin3 == amount:
                result[coin1] = num1
                result[coin2] = num2
                result[coin3] = num3
                flag = True
                break
        if flag:
            break
    if flag:
        break

if flag:
    output = []
    for coin, count in result.items():
        for _ in range(count):
            output.append(str(coin))
    print(" ".join(output))
else:
    print("-42!")
