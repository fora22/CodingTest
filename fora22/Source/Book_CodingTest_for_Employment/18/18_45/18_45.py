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

def topology_sort(n, graph, indegree):
    results = []
    result = True
    q = deque()

    for i in range(1, n + 1):
        if  indegree[i] == 0:
            q.append(i)
    
    if not q:
        return False, results

    while q:
        if len(q) > 1:
            result = False
            break
        now = q.popleft()
        results.append(now)

        for i in graph[now]:
            indegree[i] -= 1
            if indegree[i] == 0:
                q.append(i)
            elif indegree[i] < 0:
                result = False
                break

    return  result, results

def solve(n, m, node, ab):
    # v = n, e = sum(list(range(n - 1)))
    indegree = [0] * (n + 1)
    graph = [[] for i in range(n+1)]        


    for i in range(n-1):
        for j in range(i + 1, n):
            graph[node[i]].append(node[j]) # 순위별로 그래프 그림
            indegree[node[j]] += 1      # 진입차수 초기화
    
    
    for ab_value in ab:
        _a = ab_value[0]
        _b = ab_value[1]
        # 간선방향에 따라 graph update 가 달라짐 -> 예제에서는 내림차순, 오름차순일 떄 다르길래 desc로 명명함
        desc = True         

        for j in graph[_a]:
            if j == _b:
                graph[_a].remove(_b)
                graph[_b].append(_a)
                indegree[_b] -= 1
                indegree[_a] += 1
                desc = False

        if desc:
            graph[_b].remove(_a)
            graph[_a].append(_b)
            indegree[_a] -= 1
            indegree[_b] += 1

    result, results = topology_sort(n, graph, indegree)     # 위상 정렬 시작

    if not(result) or (len(results) < n):
        print("IMPOSSIBLE")
    else:
        print(*results)



for ii in range(test_case):
    solve(n[ii], m[ii], t[ii], ab[ii])