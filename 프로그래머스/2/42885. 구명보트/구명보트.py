from collections import deque


def solution(people, limit):
    answer = 0
    people = deque(sorted(people))
    
    boat_weight = 0 # limit까지만 가능
    boat_people = 0 # 최대 2명 탑승가능
    
    while len(people) > 1:
        if people[0] + people[-1] > limit:
            answer+=1
            people.pop()
        else:
            answer+=1
            people.pop()
            people.popleft()
            
    if len(people) == 1:
        answer+=1
    
    return answer