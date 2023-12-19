def solution(n, lost, reserve):
    answer = 0
    gym_suit = [1] * (n)
    for idx in lost:
        gym_suit[idx-1]-=1
    for idx in reserve:
        gym_suit[idx-1]+=1
    for idx in range(n):
        if gym_suit[idx] == 0:
            if (idx > 0 and gym_suit[idx-1] == 2):
                gym_suit[idx] += 1
                gym_suit[idx-1] -= 1
            elif (idx < n - 1 and gym_suit[idx+1] == 2):
                gym_suit[idx] += 1
                gym_suit[idx+1] -= 1
    for i in gym_suit:
        if i > 0 :
            answer+=1
    return answer


# 1 2 3 4 5
# 2 0 2 0 2
#