N, X = map(int, input().split())
Arr = list(map(int, input().split()))
min_val = min(Arr)
max_val = max(Arr)
diff = max_val - min_val
new_max = max_val - X
new_min = min_val + X
new_diff = new_max - new_min
if new_diff < diff:
    print(new_diff)
else:
    print(diff)
