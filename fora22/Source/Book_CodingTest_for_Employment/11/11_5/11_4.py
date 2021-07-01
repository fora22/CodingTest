import os, sys
dirName = os.getcwd()
sys.stdin = open(dirName + "\\input.txt", 'r')
N, M = map(int, input().split())
weights = list(map(int, input().split()))


ballCount = 0
for i in range(len(weights) - 1):
    for j in range(i, len(weights)):
        if weights[i] != weights[j]:
            ballCount += 1

print(ballCount)
