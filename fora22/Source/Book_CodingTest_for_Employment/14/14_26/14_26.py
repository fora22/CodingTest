import os
import sys
import heapq

dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

N = int(input())
cards = []
for i in range(N):
    cards.append(int(input()))

cards.sort()

heapq.heapify(cards)
countResult = 0
for _ in range(N -1):
    # ex_minimum = heapq.heappop(cards)
    # minimum =  heapq.heappop(cards)
    count = heapq.heappop(cards) + heapq.heappop(cards)
    countResult += count 
    heapq.heappush(cards, count)

print(countResult)
#######################################################
# '시간 초과'가 발생하는 코드

# import os
# import sys

# dirName = os.path.dirname(os.path.abspath(__file__))
# sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

# N = int(input())
# cards = []
# for i in range(N):
#     cards.append(int(input()))

# cards.sort()
# count = 0

# for i in range(len(cards) - 1):
#     ex_minimum = min(cards)
#     cards.remove(ex_minimum)
#     minimum = min(cards)
#     cards.remove(minimum)
#     cards.append((ex_minimum + minimum))
#     count += (ex_minimum + minimum)

# if N == 1:
#     print(0)
# else:
    # print(count)
######################################################



