'''
Greedy
참고
https://velog.io/@soo5717/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%ED%81%B0-%EC%88%98-%EB%A7%8C%EB%93%A4%EA%B8%B0-%ED%8C%8C%EC%9D%B4%EC%8D%AC
'''

def solution(number, k):
    answer = []
    numbers = list(map(int, list(number)))
    for num in numbers:
        if len(answer) == 0:
            answer.append(num)
            continue
        if k > 0:
            while answer[-1] < num:
                answer.pop()
                k -= 1
                if len(answer) == 0 or k <= 0:
                    break
        answer.append(num)

    
    return ''.join(list(map(str, answer[:len(answer) - k])))

def solution2(number, k):
    answer = [] # Stack
    
    for num in number:
        while k > 0 and answer and answer[-1] < num:
            answer.pop()
            k -= 1
        answer.append(num)
        
    return ''.join(answer[:len(answer) - k])

n = ["1924", "1231234", "4177252841"]
k = [2, 3, 4]

for i in range(3):
    print(solution(n[i], k[i]))
