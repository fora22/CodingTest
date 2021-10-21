import os
import sys
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

N = int(input())
n_array = list(map(int, sys.stdin.readline().rstrip().split()))
# n_array = [x for x in n_array if x > 0]



fix_point = []

def binary_search(array, target, start, end):
    if start > end:
        return -1       # 찾지 못하면 -1 반환
    mid = (start + end) // 2
    if array[mid] == target:
        return mid
    elif array[mid] > target:  
        return binary_search(array, target, start, mid - 1)     # 타겟보다 크면 왼쪽 탐색
    else:
        return binary_search(array, target, mid + 1, end)       # 타겟보다 작으면 오른쪽 탐색

for i in range(N):
    if i == binary_search(n_array, i, 0, N-1):   # 인덱스와 값이 같으면 fix_point에 append
        fix_point.append(i)


if fix_point == []:
    print(-1)
else:
    print(fix_point)