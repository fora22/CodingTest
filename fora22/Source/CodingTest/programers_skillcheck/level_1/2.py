def countMeasure(num): 
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