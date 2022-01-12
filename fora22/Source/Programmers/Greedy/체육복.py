'''
Greedy
참고
https://programmers.co.kr/questions/24601
https://programmers.co.kr/questions/24637
'''
def solution(n, lost, reserve):
    n_lost = set(lost) - set(reserve)
    n_reserve = set(reserve) - set(lost)
    n = n - len(n_lost)
    for lo in n_lost:
        pre = lo - 1
        after = lo + 1
        if pre in n_reserve:
            n += 1
            n_reserve.remove(pre)
            continue
        if after in n_reserve:
            n += 1
            n_reserve.remove(after)
    
    answer = n
    return answer

def solution2(n, lost, reserve):
    _reserve = [r for r in reserve if r not in lost]
    _lost = [l for l in lost if l not in reserve]
    for r in _reserve:
        f = r - 1
        b = r + 1
        if f in _lost:
            _lost.remove(f)
        elif b in _lost:
            _lost.remove(b)
    return n - len(_lost)

print(solution(3, [1,2], [2,3]))
n = [5, 5, 3]
l = [[2, 4], [2, 4], [3]]
r = [[1, 3, 5], [3], [1]]

for i in range(3):
    print(solution(n[i], l[i], r[i]))