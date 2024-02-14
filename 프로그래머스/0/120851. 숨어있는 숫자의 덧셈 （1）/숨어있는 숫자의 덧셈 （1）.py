def solution(my_string):
    answer = 0
    for s in my_string:
        if s >= '0' and s <= '9':
            answer += int(s)
    return answer