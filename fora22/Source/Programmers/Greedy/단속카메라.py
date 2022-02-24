'''
Greedy

'''
from collections import deque

def solution(routes):
    routes.sort()
    _in, _out = -3000, 3000
    answer = 0

    queue = deque(routes)
    while queue:
        cctvRange = list(range(_in, _out + 1))
        route = queue.popleft()
        if route[0] not in cctvRange:
            answer += 1
            _in, _out = route[0], route[1]
        else:
            if _in < route[0]:
                _in = route[0]
            if _out > route[1]:
                _out = route[1]

    answer += 1        
            
        

        
        
    return answer

r = [[-20,-15], [-14,-5], [-18,-13], [-5,-3]]
print(solution(r))