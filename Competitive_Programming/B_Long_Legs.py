t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    
    # Calculate the absolute difference between a and b
    diff = abs(a - b)
    
    # Calculate the smallest value of k such that k * (k + 1) >= 2 * diff
    k = int((-1 + (1 + 8 * diff) ** 0.5) // 2)
    
    # If a and b are equal or k * (k + 1) / 2 is greater than or equal to diff,
    # then the minimum number of moves is k
    if a == b or k * (k + 1) // 2 >= diff:
        print(k)
    # Otherwise, we need k + 1 moves to reach the target
    else:
        print(k + 1)
