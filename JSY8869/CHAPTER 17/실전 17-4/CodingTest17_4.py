import heapq

def dijkstra(M, graph):
    max = 0
    node = 0
    result = []
    start = 1
    INF = int(1e9)
    distance = [INF] * (M + 1)
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + 1
            #현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

    
    for i in range(M):
        if max < distance[i] & distance[i] != INF:
            max = distance[i]
            node = i
            result = []
            result.append(i)
        elif max == distance[i]:
            result.append(i)
    return(node,max,len(result))



file = open("CHAPTER 17/실전 17-4/input.txt", "r")
N, M = file.readline().strip().split()
graph = [[]for i in range(int(M))]
for _ in range(int(M)):
    A, B = (file.readline().strip().split())
    A = int(A)
    B = int(B)
    graph[A].append((B,1))
    graph[B].append((A,1))
result = file.readline().strip().split()

answer = dijkstra(int(M), graph)
for i in range(3):
    print(int(result[i]) == answer[i])


file.close()