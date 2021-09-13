from itertools import permutations

N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
temp = ['+','-','*','/']
Operator = []
result_list = []

for i in range(4):
    if B[i] != 0:
        for _ in range(B[i]):
            Operator.append(temp[i])

for Op in set(permutations(Operator)): # 순열 사용(set으로 중복 제거)
    result = A[0]
    for i in range(0,N-1):
        if Op[i] == '+':
            result = result + A[i+1]
        elif Op[i] == '-':
            result = result - A[i+1]
        elif Op[i] == '*':
            result = result * A[i+1]
        else:
            result = int(result / A[i+1])
    result_list.append(result)

print (max(result_list), min(result_list))