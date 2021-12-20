import os
import sys
from collections import deque

dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

test_case = int(sys.stdin.readline())
n = [0] * (test_case)
m = [0] * (test_case)
t = [[] for x in range(test_case)]
ab = [[] for x in range(test_case)]
for tcn in range(test_case):    # tcn: test case number
    n[tcn] = int(sys.stdin.readline())
    t[tcn] = list(map(int, sys.stdin.readline().split()))
    m[tcn] = int(sys.stdin.readline())
    for _ in range(m[tcn]):
        temp = tuple(map(int, sys.stdin.readline().split()))
        ab[tcn].append(temp)
    
def solve(n, m, node, ab):
    # v = n, e = sum(list(range(n - 1)))
    indegree = [0] * (n + 1)
    graph = [[] for i in range(n+1)]
    a, b = 0, 1

    ab_idx = []
    for ab_value in ab:
        _a = ab_value[0]
        _b = ab_value[1]
        _idx = (node.index(_a) + 1, node.index(_b) + 1)
        ab_idx.append(_idx)

    for i in range(1, n):
        for j in range(i + 1, n + 1):
            # graph[node[i]].append(node[j]) # 순위별로 그래프 그림
            graph[i].append(j) # 순위별로 그래프 그림
            indegree[j] += 1
    
    if not(len(ab)):
        pass
    else:
        for uab in ab_idx:
            graph[uab[b]].remove(uab[a])
            graph[uab[a]].append(uab[b])
            indegree[uab[a]] -= 1
            indegree[uab[b]] += 1

    result = topology_sort(n, graph, indegree)

    for idx in result:
        print(node[idx - 1], end=' ')

def topology_sort(n, graph, indegree):
    result = []
    q = deque()

    for i in range(1, n + 1):
        if  indegree[i] == 0:
            q.append(i)

    while q:
        now = q.popleft()
        result.append(now)

        for i in graph[now]:
            indegree[i] -= 1
            if indegree[i] == 0:
                q.append(i)

    return  result

for ii in range(test_case):
    solve(n[ii], m[ii], t[ii], ab[ii])
    print()


# print(n, m)
# print(t)
# print(ab)