def solution(numbers, k):
    answer = 0
    multiply_numbers = numbers * (k // (len(numbers)//2) + 1)
    print(multiply_numbers)
    pingpong = multiply_numbers[::2]
    answer = pingpong[k -1 ]
    return answer