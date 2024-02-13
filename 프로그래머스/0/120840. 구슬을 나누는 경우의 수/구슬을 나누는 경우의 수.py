import math

def solution(balls, share):
    answer = 0
    answer = math.comb(balls, share)
    return answer