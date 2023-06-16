t = int(input())

for _ in range(t):
    s = input()
    freq_dict = {}
    for c in s:
        freq_dict[c] = freq_dict.get(c, 0) + 1

    odd_freq_count = 0
    for freq in freq_dict.values():
        if freq % 2 != 0:
            odd_freq_count += 1

    if len(s) % 2 == 0 and odd_freq_count > 0:
        print("NO")
    elif len(s) % 2 == 1 and odd_freq_count > 1:
        print("NO")
    else:
        print("YES")
