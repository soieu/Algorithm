def solution(num_list, n):
    answer = []
    
    part = []
    count = 0
    for nn in num_list:
        if count == n:
            answer.append(part)
            part = []
            count = 0
        part.append(nn)
        count += 1
    answer.append(part)
    return answer