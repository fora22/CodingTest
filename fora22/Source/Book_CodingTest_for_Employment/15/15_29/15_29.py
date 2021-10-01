import os
import sys
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')


NC = list(map(int, sys.stdin.readline().rstrip().split()))
N = NC[0]
C = NC[1]

xp = []
for i in range(N):
    xp.append(int(input()))


xp.sort()
