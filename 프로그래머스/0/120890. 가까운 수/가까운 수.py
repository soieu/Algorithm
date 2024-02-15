def solution(array, n):
    answer = 0
    array.sort()
    minv = 200
    for i in array:
        if abs(n-i) < minv:
            answer = i
            minv = abs(n-i)
        elif abs(n-i) == minv and answer != i:
            break
        
    return answer