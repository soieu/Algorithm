def solution(numbers):
    answer = 0
    nums = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    
    while numbers != "":
        for idx, num in enumerate(nums):
            
            if numbers.startswith(num):
                answer *= 10
                answer += idx
                numbers = numbers[len(num):]
    return answer