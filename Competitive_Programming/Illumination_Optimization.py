def solve(M, R, X):
    n = len(X)
    i, ans = 0, 0
    while i < n:
        s = X[i]
        while i < n and X[i] - s <= R:
            i += 1
        p = X[i-1]
        while i < n and X[i] - p <= R:
            i += 1
        if i == n or X[i] - p > R:
            ans += 1
            s = X[i-1]
        elif i < n and X[i] - s > R:
            ans += 1
    if s < M:
        ans = "IMPOSSIBLE"
    return ans

T = int(input())
for t in range(1, T+1):
    M, R, N = map(int, input().split())
    X = list(map(int, input().split()))
    ans = solve(M, R, X)
    print(f"Case #{t}: {ans}")
