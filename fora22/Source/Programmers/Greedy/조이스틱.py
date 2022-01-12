'''
Greedy
참고
https://dev-note-97.tistory.com/96
'''
def solution(name):
    name_l = list(name)
    moves = [min(abs(x - ord("A")), abs(x - ord("Z")) + 1) for x in list(map(ord,name_l))]
    answer = sum(moves)

    idx = 0
    while True:
        moves[idx] = 0
        if sum(moves) == 0:
            break
        
        left, right = 1, 1

        while moves[idx - left] == 0:
            left += 1
        
        while moves[idx + right] == 0:
            right += 1
        
        if left >= right:
            idx += right
            answer += right
        else:
            idx -= left
            answer += left

    return answer

n = ["JEROEN", "JAN", "JAZ"]

for i in range(3):
    print(solution(n[i]))