def solution(array):
    answer = 0
    dict = {}
    
    # 최빈 딕셔너리 저장
    for i in array:
        if dict.get(i, -1) == -1 :
            dict[i] = 1
        else:
            dict[i] = dict[i] + 1
        
    # 최빈값 구하기
    maxNum = 0
    target = 0
    count = 0
    for key, value in dict.items():
        if maxNum == value:
            count = 1
        elif maxNum < value:
            maxNum = max(maxNum, value)
            target = key
            count = 0
    if count == 1:
        return -1
    answer = target
    return answer