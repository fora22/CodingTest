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
            for idx, pr in enumerate(p):
                if price > pr:
                    temp = idx + 1
                    break
            answer.append(temp)

    return answer

p = [1, 2, 3,4, 3, 2, 3]

print(solution(p))