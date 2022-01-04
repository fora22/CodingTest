'''
Heap
참고
https://programmers.co.kr/questions/24600
'''

import heapq

def solution(scoville, K):
    heapq.heapify(scoville)

    cnt = 0
    while scoville[0] < K:
        if len(scoville) <= 1:
            return -1
        first = heapq.heappop(scoville)
        second = heapq.heappop(scoville)
        heapq.heappush(scoville, first + second * 2)
        cnt += 1
    
    answer = cnt
    return answer


s = [1, 2, 3, 9, 10, 12]
k = 7

print(solution(s, k))
