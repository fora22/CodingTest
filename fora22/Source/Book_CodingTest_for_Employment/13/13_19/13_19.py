import os
import sys
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

N = int(input())
numbers = list(map(int, input().split()))
operations = list(map(int, input().split()))  # plus, minus, multiply, divide

maxNum = -10**9
minNum = 10**9

def dfs(num, depth, pl, mi, mu, di):
    global maxNum, minNum
    if depth == N:
        maxNum = max(num, maxNum)
        minNum = min(num, minNum)
        return

    if pl > 0:
        dfs(num + numbers[depth], depth + 1, pl - 1, mi, mu, di)
    if mi > 0:
        dfs(num - numbers[depth], depth + 1, pl, mi - 1, mu, di)
    if mu > 0:
        dfs(num * numbers[depth], depth + 1, pl, mi, mu - 1, di)
    if di > 0:
        dfs(num / numbers[depth], depth + 1, pl, mi, mu, di - 1)

dfs(numbers[0], 1, operations[0], operations[1], operations[2], operations[3])
print(maxNum)
print(minNum)