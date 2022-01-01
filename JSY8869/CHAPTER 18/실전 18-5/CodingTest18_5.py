from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())
    rank = list(map(int, input().split())) # 작년 순위
    graph = [[False] * (n + 1) for _ in range(n + 1)] # 자기보다 순위가 낮으면 True
    indegree = [0] * (n + 1) # 순위가 더 높은 팀의 개수

    for i in range(n):
        for j in range(i + 1, n):
            graph[rank[j]][rank[i]] = True
            indegree[rank[i]] += 1

    m = int(input())
    for _ in range(m):
        a, b = map(int, input().split())
        if not graph[a][b]: # 순위가 바뀐 경우 a와 b의 값을 바꿈
            a, b = b, a
        graph[a][b], graph[b][a] = False, True # 그래프 값도 a와 b를 바꿈
        indegree[a] += 1 # 순위가 더 높은 팀의 개수도 a와 b를 + or - 해줌
        indegree[b] -= 1
    print(graph)
    q = deque()
    answer = []
    count = 0
    for i in range(1, n + 1): # 꼴등 찾기
        if indegree[i] == 0:
            count += 1
            q.append(i)

    if count != 1:
        if count > 1: # 꼴등이 2개 이상인 경우
            print("?")
        elif count == 0: # 꼴등이 없는 경우
            print("IMPOSSIBLE")
        continue
    print(indegree)

    while q and count == 1:
        count = 0
        now = q.popleft()
        answer.append(now)
        for i in range(1, n + 1):
            if graph[now][i]: # i번째가 now보다 순위가 낮은 경우
                indegree[i] -= 1 # 찾은거 체크
                print(indegree)
                if indegree[i] == 0: # 더이상 순위가 낮은 경우가 없는 경우
                    count += 1
                    q.append(i)
    if count > 1: # 사이클 발생
        print("?")
    elif len(answer) != n: # 계산 불가
        print("IMPOSSIBLE")
    else:
        print(*answer[::-1])