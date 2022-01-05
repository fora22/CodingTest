'''
Queue
'''
from collections import deque

def solution(bridge_length, weight, truck_weights):
    queue = deque(truck_weights)
    bridge = deque([])
    cnt = 1
    truck_w = queue.popleft()
    bridge.append([truck_w, 1])
    while (len(queue) != 0) or (len(bridge) != 0):
        for i in range(len(bridge)):
            bridge[i][1] += 1       # bridge 에 있는 truck 한 칸 씩 이동
        if bridge[0][1] > bridge_length:
            bridge.popleft()        # bridge를 지나간 truck은 제거
        bridge_weight = sum([x[0] for x in bridge])     # bridge 위에 있는 truck 무게 합

        if len(queue) != 0:
            first_q = queue[0]
        else:
            first_q = 0
        if ((bridge_weight + first_q) <= weight) and len(queue) != 0:      
            # queue가 비어있지 않고 bridge 무게가 견딜 수 있다면 진행
            truck_w = queue.popleft()
            bridge.append([truck_w, 1])
        cnt += 1

        
    answer = cnt
    return answer


b_l = [2, 100, 100]
w = [10, 100, 100]
t_w = [[7,4,5,6], [10], [10,10,10,10,10,10,10,10,10,10]]

for i in range(3):
    print(solution(b_l[i], w[i], t_w[i]))
