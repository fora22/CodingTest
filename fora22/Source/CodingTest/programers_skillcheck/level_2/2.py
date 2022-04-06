'''
트럭 여러 대가 강을 가로지르는 일차선 다리를 정해진 순으로 건너려 합니다. 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다. 다리에는 트럭이 최대 bridge_length대 올라갈 수 있으며, 다리는 weight 이하까지의 무게를 견딜 수 있습니다. 단, 다리에 완전히 오르지 않은 트럭의 무게는 무시합니다.

예를 들어, 트럭 2대가 올라갈 수 있고 무게를 10kg까지 견디는 다리가 있습니다. 무게가 [7, 4, 5, 6]kg인 트럭이 순서대로 최단 시간 안에 다리를 건너려면 다음과 같이 건너야 합니다.

경과 시간	다리를 지난 트럭	다리를 건너는 트럭	대기 트럭
0	[]	[]	[7,4,5,6]
1~2	[]	[7]	[4,5,6]
3	[7]	[4]	[5,6]
4	[7]	[4,5]	[6]
5	[7,4]	[5]	[6]
6~7	[7,4,5]	[6]	[]
8	[7,4,5,6]	[]	[]
따라서, 모든 트럭이 다리를 지나려면 최소 8초가 걸립니다.

solution 함수의 매개변수로 다리에 올라갈 수 있는 트럭 수 bridge_length, 다리가 견딜 수 있는 무게 weight, 트럭 별 무게 truck_weights가 주어집니다. 이때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 return 하도록 solution 함수를 완성하세요.

제한 조건
bridge_length는 1 이상 10,000 이하입니다.
weight는 1 이상 10,000 이하입니다.
truck_weights의 길이는 1 이상 10,000 이하입니다.
모든 트럭의 무게는 1 이상 weight 이하입니다.
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
t_w = [[7,4,5,6],
        [10],
        [10,10,10,10,10,10,10,10,10,10]]

for i in range(3):
    print(solution(b_l[i], w[i], t_w[i]))