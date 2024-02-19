def solution(my_string):
    answer = ''
    answer = my_string.lower();
    answer = sorted(answer)
    answer = ''.join(answer)
    return answer