def is_collision_possible(word_list, mapping):
    encoded_dict = {}
    for word in word_list:
        encoded_word = ""
        for letter in word:
            encoded_word += str(mapping[ord(letter) - ord('A')])
        if encoded_word in encoded_dict:
            return "YES"
        encoded_dict[encoded_word] = True
    return "NO"

t = int(input())
for i in range(1, t+1):
    mapping = list(map(int, input().split()))
    word_count = int(input())
    word_list = []
    for j in range(word_count):
        word_list.append(input().strip())
    result = is_collision_possible(word_list, mapping)
    print("Case #{}: {}".format(i, result))
