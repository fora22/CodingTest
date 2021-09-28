import os
import sys

dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

N = int(input())
stages = list(map(int, input().split()))
stages.sort()


fail = {}
lenS = len(stages)
for st in range(1, N + 1):
    countStages = stages.count(st)
    fail[st] = countStages / lenS
    lenS -= countStages
failure = sorted(fail, key=lambda x : fail[x], reverse=True)
print(failure)
print(fail)