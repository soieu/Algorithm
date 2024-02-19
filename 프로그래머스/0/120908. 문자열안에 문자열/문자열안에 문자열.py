def solution(str1, str2):
    answer = 2
    for i in range(len(str1)-len(str2)+1):
        if str1[i] == str2[0]:
            for j in range(len(str2)):
                if j == len(str2) -1 and str2[j] == str1[i+j]:
                    answer = 1
    if str1 == str2:
        answer = 1
    return answer