import os
import sys
import heapq
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')


N, M = map(int, sys.stdin.readline().rstrip().split())

INF = int(1e9)
graph = [[] for i in range(N + 1)]
distance = [INF] * (N+1)

for _ in range(M):
     A, B = map(int, sys.stdin.readline().split())
     graph[A].append((B, 1))
     graph[B].append((A, 1))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(1)

safeDistance = max([x for x in distance if x != INF])
safeBarn = distance.index(safeDistance)
countSafeBarn = distance.count(safeDistance)

print(safeBarn, safeDistance, countSafeBarn)