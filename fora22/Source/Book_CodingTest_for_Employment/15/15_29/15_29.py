import os
import sys
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

N,C = map(int, sys.stdin.readline().split())
array = [int(sys.stdin.readline()) for _ in range(N)]

array.sort()

start = 1
end = array[-1] - array[0]

maxLength = 0

while (start <= end):
    mid = (start + end) // 2
    install = array[0]
    count = 1

    for x in array:
        if (x >= install + mid):
            install = x
            count = count + 1
    
    if count >= C:
        maxLength = max([maxLength, mid])
        start = mid + 1
    else:
        end = mid - 1

print(maxLength)