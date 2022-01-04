'''
Heap
참고
https://soohyun6879.tistory.com/136
'''
import heapq

def solution(jobs):
    answer, nowTime, cnt = 0, 0, 0
    number_of_jobs = len(jobs)
    startTime = -1

    heap = []
    while cnt < len(jobs):
        for jb in jobs:
            if startTime < jb[0] <= nowTime:
                heapq.heappush(heap, (jb[1], jb[0]))

        if len(heap) > 0:
            task = heapq.heappop(heap)
            startTime = nowTime
            nowTime += task[0]
            answer += nowTime - task[1]
            cnt += 1
        else:
            nowTime += 1
    answer = int(answer / number_of_jobs)
    return answer


j = [[0, 3], [1, 9], [2, 6]]

print(solution(j))