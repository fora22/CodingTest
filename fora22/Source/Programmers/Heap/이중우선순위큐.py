'''
Heap
'''
import heapq

def maxHeapPop(maxHeap):
    maxHeap = [(x[1], x[0]) for x in maxHeap]
    heapq.heapify(maxHeap)

    maxNum = heapq.heappop(maxHeap)

    maxHeap = [(x[1], x[0]) for x in maxHeap]
    heapq.heapify(maxHeap)

    return (maxNum[1], maxNum[0]), maxHeap

def solution(operations):
    heap = []
    for opers in operations:
        operation = opers[0]
        number = int(opers[1:])
        
        if operation == "I":
            heapq.heappush(heap, (number, -number))
        else:
            if not(len(heap)):
                continue
            elif number == 1:
                _, heap = maxHeapPop(heap)
            else:
                heapq.heappop(heap) 

    answer = []
    if not(len(heap)):
        answer = [0, 0]
    else:
        maxNumber, heap = maxHeapPop(heap)
        minNumber = heapq.heappop(heap)
        answer = [maxNumber[0], minNumber[0]]

    return answer


o = [
    ["I 16", "D 1"],
    ["I 7", "I 5", "I -5", "D -1"]
]

for i in range(2):
    print(solution(o[i]))