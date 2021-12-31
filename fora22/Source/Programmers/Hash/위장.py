'''
Hash 문제
참고
https://programmers.co.kr/learn/courses/30/lessons/42578/solution_groups?language=python3
'''
# 모든 조합의 수 : (종류 + 1)을 모두 곱한 후, 아무것도 안입은 경우의 수 1 빼기
def solution(clothes):
    clothes_type = {}

    for _, t in clothes:
        if t not in clothes_type:
            clothes_type[t] = 2
        else:
            clothes_type[t] += 1

    count = 1
    for num in clothes_type.values():
        count *= num
    answer = count - 1
    return answer


def solution2(clothes):
    from collections import Counter
    from functools import reduce
    cnt = Counter([kind for name, kind in clothes])
    answer = reduce(lambda x, y: x*(y+1), cnt.values(), 1) - 1
    return answer


c = [
    [["yellowhat", "headgear"], ["bluesunglasses","eyewear"], ["green_turban", "headgear"]],
    [["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]
]
for i in range(2):
    print(solution2(c[i]))