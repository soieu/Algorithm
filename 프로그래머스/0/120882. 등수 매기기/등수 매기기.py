def solution(score):
    answer = []
    
    avg = [sum(i)/2 for i in score] 
    a = sorted(avg[:], reverse=True)
    
    print(avg)

    for i in avg:
        answer.append(a.index(i)+1)
        
    
    return answer