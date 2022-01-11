from collections import deque
import math as m
import numpy as np

def solution(answers):
    queue = deque(answers)
    supo_1 = [1,2,3,4,5] * m.ceil((len(answers) / 5))
    supo_2 = [2,1,2,3,2,4,2,5] * m.ceil((len(answers) / 8))
    supo_3 = [3,3,1,1,2,2,4,4,5,5] * m.ceil((len(answers) / 10))

    count = [0] * 3
    idx = 0
    supo_answer = [0,0,0]
    while queue:
        answer = queue.popleft()
        supo_answer = supo_1[idx], supo_2[idx], supo_3[idx]
        count += np.equal(supo_answer, [answer, answer, answer])
        idx += 1

    result = []
    max_cnt = max(count)
    for i in range(3):
        if max_cnt == count[i]:
            result.append(i + 1)

    return result


def solution2(answers):
    pattern1 = [1,2,3,4,5]
    pattern2 = [2,1,2,3,2,4,2,5]
    pattern3 = [3,3,1,1,2,2,4,4,5,5]
    score = [0, 0, 0]
    result = []

    for idx, answer in enumerate(answers):
        if answer == pattern1[idx%len(pattern1)]:
            score[0] += 1
        if answer == pattern2[idx%len(pattern2)]:
            score[1] += 1
        if answer == pattern3[idx%len(pattern3)]:
            score[2] += 1

    for idx, s in enumerate(score):
        if s == max(score):
            result.append(idx+1)

    return result

a = [[1,2,3,4,5], [1,3,2,4,2]]
for i in range(2):
    print(solution(a[i]))