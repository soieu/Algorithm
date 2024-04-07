def solution(phone_book):
    phone_book.sort()  # 전화번호부를 정렬
    for i in range(len(phone_book) - 1):
        # 정렬된 리스트에서 현재 전화번호가 다음 전화번호의 접두어인지 확인
        if phone_book[i+1].startswith(phone_book[i]):
            return False  # 접두어 관계가 발견되면 False 반환
    return True 