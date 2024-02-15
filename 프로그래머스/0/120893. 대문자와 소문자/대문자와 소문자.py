def solution(my_string):
    answer = ''
    for ch in my_string:
        if ch >= 'a' and ch <= 'z':
            ch = chr(ord(ch) - ord("a") + ord("A"))
            answer += ch
        else:
            ch = chr(ord(ch) + ord("a") - ord("A"))
            answer += ch
            
    return answer