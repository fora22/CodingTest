'''
Greedy
크루스칼 알고리즘 사용
참고
https://freedeveloper.tistory.com/389?category=888096
'''

# 특정 원소가 속한 집합을 찾기
def find_parent(parent, x):
    # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if parent[x] != x:
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


def solution(n, costs):
    # 노드의 개수와 간선(Union 연산)의 개수 입력 받기
    e = len(costs)
    parent = [0] * (n + 1) # 부모 테이블 초기화하기

    # 모든 간선을 담을 리스트와, 최종 비용을 담을 변수
    edges = []
    result = 0

    # 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for i in range(1, n + 1):
        parent[i] = i

    A = 0
    B = 1
    COST = 2
    for i in range(e):
        edges.append((costs[i][COST], costs[i][A], costs[i][B]))

    edges.sort()

    # 간선을 하나씩 확인하며
    for edge in edges:
        cost, a, b = edge
        # 사이클이 발생하지 않는 경우에만 집합에 포함
        if find_parent(parent, a) != find_parent(parent, b):
            union_parent(parent, a, b)
            result += cost

    print(result)

    return result


c = [[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]
node = 4
print(solution(node, c))