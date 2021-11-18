def floyd(n, graph):

  for k in range(1, 1 + n):
    for a in range(1, 1 + n):
      for b in range(1, 1 + n):
        graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])
  
  for i in range(1, 1 + n):
    for j in range(1, 1 + n):
      if graph[a][b] == INF:
        print("INF", end=" ") 
      else:
        print(graph[i][j], end=" ")
  return (graph)


file = open("CHAPTER 17/실전 17-1/input.txt", "r")
N = int(file.readline())
M = int(file.readline())
INF = int(1e9)
graph = [[INF] * (N+1) for _ in range((N+1))]
for i in range(1, 1 + N):
  for j in range(1, 1 + N):
    if i == j:
      graph[i][j] = 0
for _ in range(int(M)):
    A, B, C = (file.readline().strip().split())
    A = int(A)
    B = int(B)
    graph[A][B] = min(graph[A][B], int(C))
result = []
for _ in range(N):
  result.append(file.readline().strip().split())

graph = floyd(N,graph)

for a in range(0, N):
  for b in range(0, N):
    print(graph[a+1][b+1] == int(result[a][b]))