import os
import sys
import copy

dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')


def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

N = int(sys.stdin.readline())
planets = []
class planet():     # sort시 index 정보가 사라지므로 class 생성
    def __init__(self, idx, X, Y, Z) -> None:
        self.idx = idx
        self.X = X
        self.Y = Y
        self.Z = Z


for i in range(N):
    x_cor, y_cor, z_cor = map(int, sys.stdin.readline().split())
    planets.append(planet(i, x_cor, y_cor, z_cor))

edges = []

p = copy.deepcopy(planets)

# x, y, z별 거리 차의 min()이므로 행성마다 3개의 간선이 있다고 가정
# x, y, z별로 정렬하여 간선을 update
p.sort(key=lambda pl: pl.X)         
for i in range(len(p) - 1):
    _cost_ = abs(p[i].X - p[i+1].X)
    _a_ = p[i].idx
    _b_ = p[i+1].idx
    edges.append((_cost_, _a_, _b_))

p.sort(key=lambda pl: pl.Y)
for i in range(len(p) - 1):
    _cost_ = abs(p[i].Y - p[i+1].Y)
    _a_ = p[i].idx
    _b_ = p[i+1].idx
    edges.append((_cost_, _a_, _b_))

p.sort(key=lambda pl: pl.Z)
for i in range(len(p) - 1):
    _cost_ = abs(p[i].Z - p[i+1].Z)
    _a_ = p[i].idx
    _b_ = p[i+1].idx
    edges.append((_cost_, _a_, _b_))    

result = 0

parent = [x for x in range(N)]

edges.sort() 

# 크루스칼 알고리즘 실행
for idx, edge in enumerate(edges):
    _cost, __a, __b = edge
    if find_parent(parent, __a) != find_parent(parent, __b):
        union_parent(parent, __a, __b)
        result += _cost

print(result)