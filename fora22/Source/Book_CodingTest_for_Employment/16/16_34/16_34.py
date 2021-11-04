import os
import sys
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

N = int(sys.stdin.readline().rstrip())

power = list(map(int, sys.stdin.readline().rstrip().split()))

power.reverse()
length = [1 for _ in range(N)]  # 길이 담는 array

for i in range(1, len(power)):
    for j in range(i):
        if power[i] > power[j]:
            length[i] = max(length[i], length[j] + 1)

print(N - max(length))
