import os
dirName = os.path.dirname(os.path.abspath(__file__))
import sys
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')
read = sys.stdin.readline

n = int(read())
m = int(read())

INF = int(1e9)
graph = [[INF] * (n+1) for i in range(n + 1)]

for a in range(1, n+1):
    for b in range(1, n+1):
        if a == b:
            graph[a][b] = 0

for _ in range(m):
    a, b, c = map(int, read().split())
    graph[a][b] = min(graph[a][b], c)

for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            if a == b:
                graph[a][b] = 0
            else:
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])


for a in range(1, n+1):
    for b in range(1, n+1):
        if graph[a][b] == INF:
            print("0", end=' ')
        else:
            print(graph[a][b], end=' ')
    print()