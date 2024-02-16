def solution(my_string):
    answer = 0
    operand = 0
    sign = 1
    for s in my_string:
        if s >= '0' and s <= '9':
            operand *= 10
            operand += int(s)
            print(operand)
        elif s == '-':
            if operand != 0:
                answer += operand * sign
                operand = 0
            sign = -1
        elif s == '+':
            if operand != 0:
                answer += operand * sign
                operand = 0
            sign = 1
    answer += operand * sign
        
            
            
    return answer