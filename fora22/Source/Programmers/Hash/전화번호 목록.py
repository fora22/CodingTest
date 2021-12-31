'''
Hash 문제
참고
https://programmers.co.kr/learn/courses/30/lessons/42577/solution_groups?language=python3
'''

def solution(phone_book):
    answer = True
    hash_map = {}
    for phone_number in phone_book:
        hash_map[phone_number] = 1
    for phone_number in phone_book:
        temp = ""
        for number in phone_number:
            temp += number
            if temp in hash_map and temp != phone_number:
                answer = False
    return answer

def solution2(phoneBook):
    phoneBook = sorted(phoneBook)

    for p1, p2 in zip(phoneBook, phoneBook[1:]):
        if p2.startswith(p1):
            return False
    return True


p_b = [
    ["119", "97674223", "1195524421"],
    ["123", "456", "789"],
    ["12", "123", "1235", "567", "88"]
]

for i in range(3):
    print(solution2(p_b[i]))