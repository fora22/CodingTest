from collections import deque

def solution(prices):
    answer = []
    
    p = deque(prices)
    while len(p) != 0:
        price = p.popleft()
        if len(p) == 0:
            answer.append(0)
            break
        min_price = min(p)
        if price <= min_price:
            answer.append(len(p))
        else:
            temp = p.index(min_price) + 1
            answer.append(temp)

    return answer

p = [1, 2, 3, 2, 3]

print(solution(p))