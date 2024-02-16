def solution(s1, s2):
    answer = 0
    
    for ss1 in s1:
        if s2.count(ss1):
            answer += 1
    return answer