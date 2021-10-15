import os
import sys
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

N,C = map(int, sys.stdin.readline().split())
xp = [int(sys.stdin.readline()) for _ in range(N)]

xp.sort()
