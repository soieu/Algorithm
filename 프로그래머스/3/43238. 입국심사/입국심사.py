def solution(n, times):
    answer = 0x7ffffffffff
    
    left = 1
    right = max(times) * n
    
    while left <= right:
        mid = int((left+right) / 2)
        temp = 0
        
        for time in times:
            temp += int(mid / time)
        
        if temp >= n:
            if answer > mid:
                answer = mid
            right = mid - 1
        else:
            left = mid + 1
    return answer