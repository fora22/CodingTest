'''
Queue
'''
from collections import deque

def solution(priorities, location):
    q = deque([])
    result = []

    for idx, p in enumerate(priorities):
        q.append((idx, p))
    maxP = max(q, key=lambda x: x[1])[1] 

    while len(q) != 0:
        if q[0][1] < maxP:
            temp = q.popleft()
            q.append(temp)
        elif q[0][1] == maxP:
            result.append(q.popleft())
            if len(q) == 0:
                break
            maxP = max(q, key=lambda x: x[1])[1]

    answer = 0
    for idx, val in enumerate(result):
        if val[0] == location:
            answer = idx + 1
            break

    return answer

def solution2(priorities, location):
    queue =  [(i,p) for i,p in enumerate(priorities)]
    answer = 0
    while True:
        cur = queue.pop(0)
        if any(cur[1] < q[1] for q in queue):
            queue.append(cur)
        else:
            answer += 1
            if cur[0] == location:
                return answer


p = [[2, 1, 3, 2], [1, 1, 9, 1, 1, 1]]
l = [2, 0]

for i in range(2):
    print(solution(p[i], l[i]))