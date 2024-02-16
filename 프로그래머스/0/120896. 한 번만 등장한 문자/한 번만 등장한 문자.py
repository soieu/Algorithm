def solution(s):
    answer = ''
    for aph in range(ord('a'), ord('z')+1):
        if s.count(chr(aph)) == 1:
            answer+=chr(aph)
    return answer