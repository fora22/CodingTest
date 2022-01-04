'''
Queue
'''
import math as m
from collections import deque

def solution(progresses, speeds):
    dueTime = [m.ceil((100 - progresses[i]) / speeds[i]) for i in range(len(progresses))]

    q = deque(dueTime)
    answer = []
    cnt = 1
    due = q.popleft()
    while(len(q) != 0):
        if due < q[0]:
            answer.append(cnt)
            due = q[0]
            cnt = 0
        else:
            q.popleft()
            cnt += 1
    
    answer.append(cnt)
    
    return answer

p = [[93, 30, 55], [95, 90, 99, 99, 80, 99]]

s = [[1, 30, 5], [1, 1, 1, 1, 1, 1]]

for i in range(2):
    print(solution(p[i], s[i]))