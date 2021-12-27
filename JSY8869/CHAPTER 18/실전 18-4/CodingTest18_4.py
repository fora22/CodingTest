# 특정 원소가 속한 집합을 찾기
def find_parent(parent, x):
    # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if parent[x] != x: # 부모가 자기 자신인 경우를 찾을때까지
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

# 두 원소가 속한 집합을 합치기
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


v = int(input()) # 노드의 개수
parent = [0] * (v + 1)

tunnels = []
result = 0

for i in range(1, v + 1):
    parent[i] = i

x = []
y = []
z = []

for i in range(v):
    a, b, c = map(int, input().split())
    x.append([a,i])
    y.append([b,i])
    z.append([c,i])

# 좌표 오름차순 정렬
x.sort()
y.sort()
z.sort()

# 간선을 하나씩 확인
for i in range(v-1):
  tunnels.append([abs(x[i+1][0] - x[i][0]), x[i][1], x[i+1][1]])
  tunnels.append([abs(y[i+1][0] - y[i][0]), y[i][1], y[i+1][1]])
  tunnels.append([abs(z[i+1][0] - z[i][0]), z[i][1], z[i+1][1]])

tunnels.sort()

for tunnel in tunnels:
    cost, a, b = tunnel

    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b) # 공통된 부모를 가지도록
        result += cost
        
print(result)