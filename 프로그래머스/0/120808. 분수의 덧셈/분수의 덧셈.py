import math

def solution(numer1, denom1, numer2, denom2):
    answer = []
    result_numer = numer1 * denom2 + numer2 * denom1
    result_denom = denom1 * denom2
    gcd = math.gcd(result_numer, result_denom)
    answer = [result_numer // gcd, result_denom // gcd]
    
    
    return answer