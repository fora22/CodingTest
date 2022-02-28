# 통과못함 런타임 에러, 기수정렬로 풀어야 함
def solution(n):
    temp = [int(x) for x in str(n)]
    temp.sort(reverse=True)
    count = [0] * (max(temp) + 1)
    for i in range(len(temp)):
        count[temp[i]] += 1

    answer = []
    for i in range(len(count)):
        for j in range(count[i]):
            print(i, end=' ')
            answer.append(i)
    
    answer.sort(reverse=True)
    return answer

print(solution(118372))
