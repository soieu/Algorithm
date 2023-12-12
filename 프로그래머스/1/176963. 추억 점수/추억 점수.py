def solution(name, yearning, photo):
    answer = []
    for one_photo in photo:
        memory_score = 0
        for person in one_photo:
            if name.count(person) != 0:
                memory_score += yearning[name.index(person)]
                print(memory_score)
        answer.append(memory_score)
    return answer