import math

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    gcd, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return gcd, x, y

t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    if k == 1:
        print("YES")
    elif k % 2 == 0 and n % 2 == 1:
        print("NO")
    else:
        gcd, x, y = extended_gcd(2, k)
        if n % gcd == 0:
            print("YES")
        else:
            print("NO")
