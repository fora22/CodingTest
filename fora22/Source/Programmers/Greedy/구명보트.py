'''
Greedy
참고
https://somjang.tistory.com/entry/Programmers-%EA%B5%AC%EB%AA%85%EB%B3%B4%ED%8A%B8-Python
'''

def solution(people, limit):
    answer = 0

    people.sort()   # 내림차순 정렬
    first, last = 0, len(people) - 1    # 양 끝에서 시작

    while first <= last:
        answer += 1
        if people[first] + people[last] <= limit:   # 2명이 탈 수 있으면 양쪽 모두 떙김
            first += 1
        last -= 1           # 그렇지 않으면 몸무게가 가장 무거운 사람부터 내보냄

    return answer


p = [[70, 50, 80, 50], [70, 80, 50]]
l = [100, 100]

for i in range(2):
    print(solution(p[i], l[i]))