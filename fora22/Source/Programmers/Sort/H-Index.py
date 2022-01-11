def get_length(_citations, _h):
    for i, c in enumerate(_citations):
        if c >= _h:
            return len(_citations[i:])

def solution(citations):
    result = []
    citations.sort()
    for h in range(citations[-1]):
        over_legnth = get_length(citations, h)
        if over_legnth >= h and (len(citations) - over_legnth) <= h:
            result.append(h)
        
    if len(result) == 0:
        answer = 0
    else:
        answer = max(result)

    return answer


def solution2(citations):
    citations.sort(reverse=True)
    answer = max(map(min, enumerate(citations, start=1)))
    return answer

c = [3, 0, 6, 1, 5]
print(solution2(c))