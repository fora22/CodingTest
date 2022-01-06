'''
Stack
참고
https://deftkang.tistory.com/175
'''

def solution(prices):
    answer = [0]*len(prices)
    
    s = []
    for i, p in enumerate(prices):
        while s and prices[s[-1]] > p:
            j = s.pop()
            answer[j] = i-j            
        s.append(i)
    
    while s:
        i = s.pop()
        answer[i] = len(prices)-1-i

    return answer

p = [1, 2, 3,4, 3, 2, 3]

print(solution(p))