def solution(numbers, direction):
    answer = []
    if direction == "right":
        last = numbers.pop()
        numbers.insert(0, last)
        answer = numbers
    else:
        first = numbers[0]
        numbers.remove(first)
        numbers.append(first)
        
        answer = numbers
    
    return answer