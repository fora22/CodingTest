import os
import sys
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

N = int(sys.stdin.readline().rstrip())

dayTerm = 0  # 상담 기간 index
price = 1   # 상담료 index
schedule = [[-1, -1]]

for _ in range(N):
    day, pay = map(int, sys.stdin.readline().rstrip().split())
    schedule.append([day,pay])

dpTable = [0] * (15 + 5) # max N + max T
getMoney = 0
for i in range(1, N + 1):
    getMoney = max(getMoney, dpTable[i])
    next_idx = i + schedule[i][dayTerm]

    dpTable[next_idx] = max(dpTable[next_idx], getMoney + schedule[i][price])

result = dpTable[:N+2]

print(max(result))