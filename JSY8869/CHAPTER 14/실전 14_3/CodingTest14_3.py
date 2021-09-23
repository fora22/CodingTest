def solution(N, stages):
    result = {}
    num = len(stages)

    for stage in range(1, N+1):
        if num == 0: # 모두 클리어한 경우 실패율 = 0
            result[stage] = 0
            pass

        count = stages.count(stage) # count 함수 사용 클리어 수 계산
        result[stage] = count / num # 실패율 계산
        num -= count
            
    result = sorted(result, key= lambda x : result[x], reverse=True) # value값으로 정렬(실패율)

    return result