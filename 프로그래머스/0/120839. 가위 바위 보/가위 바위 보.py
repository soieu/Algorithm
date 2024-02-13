def solution(rsp):
    answer = ''
    dic = {'2' : '0', '5' : '2', '0' : '5'}
    for one in rsp:
        answer += dic[one]
    return answer