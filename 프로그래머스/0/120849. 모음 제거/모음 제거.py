def solution(my_string):
    answer = ''
    vowels = ['a','e','i','o','u']
    my_list = list(my_string)
    for vowel in vowels:
        cnt = my_string.count(vowel)
        for _ in range(cnt):
            my_list.remove(vowel)
    answer = "".join(my_list)
    return answer