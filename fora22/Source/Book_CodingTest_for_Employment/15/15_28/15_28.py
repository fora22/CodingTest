import os
import sys
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

N = int(input())
n_array = list(map(int, sys.stdin.readline().rstrip().split()))


# n_array = [x for x in n_array if x > 0]
global fix_point
fix_point = []

def binary_search(array, target, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    if array[mid] == target:
        return target
    elif array[mid] > target:
        return binary_search(array, target, start, mid - 1)
    else:
        return binary_search(array, target, mid + 1, end)

for i in range(N):
    binary_search(n_array, i,0, N - 1)