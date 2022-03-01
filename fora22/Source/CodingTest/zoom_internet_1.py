'''
임의의 자연수 n으로 나누었을 때, 그 몫과 나머지가 같아지는 자연수들을 모두 더한 값을 반환하도록 solution 함수를 완성하세요.
'''

def solution(n):
    answer = 0
    for i in range(1, n):
        answer += (n*i + i)
    return answer

print(solution(2))