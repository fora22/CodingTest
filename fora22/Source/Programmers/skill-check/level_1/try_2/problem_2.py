'''
문제 설명
두 정수 left와 right가 매개변수로 주어집니다. 
left부터 right까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수를 완성해주세요.
'''

def countMeasure(num):  
    # 약수의 개수를 구하여 1 또는 -1 를 return하는 함수
    count = 0
    for i in range(1, num+1):
        if num % i == 0:
            count += 1

    result = 1
    if count % 2 == 0:
        result = 1
    else:
        result = -1
    return result

def solution(left, right):
    answer = 0
    for n in range(left, right+1 ,1):
        answer += (countMeasure(n) * n)
    return answer

l = [13, 24]
r = [17, 27]
for i in range(2):
    print(solution(l[i] ,r[i]))