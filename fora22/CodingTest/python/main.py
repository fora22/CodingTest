import os, sys
dirName = os.getcwd()
sys.stdin = open(dirName + "\\input.txt", 'r')

N = int(input())
coins = list(map(int,input().split()))
target = 1
coins.sort()
for c in coins:
    if target < c:
        break
    target += c

print(target)

