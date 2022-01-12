def solution(name):
    name_l = list(name)
    temp = [min(abs(x - ord("A")), abs(x - ord("Z"))) for x in list(map(ord,name_l))]
    answer = sum(temp) + len(temp) - 1
    return answer

n = ["JEROEN", "JAN", "JAZ"]

for i in range(3):
    print(solution(n[i]))