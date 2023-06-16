test = int(input())

for _ in range(test):
    nx, dy = map(int, input().split())
    num = input()

    # Find the leftmost position to insert the additional digit
    for i in range(nx):
        if int(num[i]) < dy:
            num = num[:i] + str(dy) + num[i:]
            break
    else:
        num += str(dy)

    print(num)
