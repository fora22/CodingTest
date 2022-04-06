'''
DP
https://programmers.co.kr/learn/courses/30/lessons/42895?language=python3
참고
https://velog.io/@j_user0719/N%EC%9C%BC%EB%A1%9C-%ED%91%9C%ED%98%84-PYTHON
'''
def solution(N, number):
    answer = -1     # 최솟값이 9이상이면 -1 return을 위해 -1로 초기화
    dp = []
    if N == number: # 같은 수일경우 바로 1로 return
        return 1

    for i in range(1,9):    # 1~8까지만 dp 업데이트
        allCase = set()
        NList = int(str(N) * i)     # 5, 55, 555 등의 
        allCase.add(NList)

        for j in range(0, i-1):
            for op1 in dp[j]:
                for op2 in dp[-j-1]:
                    allCase.add(op1 - op2)
                    allCase.add(op1 + op2)
                    allCase.add(op1 * op2)
                    if op2 != 0:
                        allCase.add(op1 // op2)
                        
        if number in allCase:
            answer = i
            break
            
        dp.append(allCase) 
    return answer

n = [5, 2]
num = [12, 11]
for i in range(2):
    print(solution(n[i], num[i]))