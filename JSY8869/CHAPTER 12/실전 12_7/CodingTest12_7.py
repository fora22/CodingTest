# n = 외벽의 총 둘레
# weak = 취약 지점의 위치
# dist = 각 친구가 1시간 동안 이동할 수 있는 거리
def solution(n, weak, dist):
    answer = 0
    for i in range(len(weak)): # weak를 2배로 늘려서 선형으로 펴서 사용
        weak.append(weak[i]+n)

    return answer

solution(12,[1, 5, 6, 10],[1, 2, 3, 4])