# n = 외벽의 총 둘레
# weak = 취약 지점의 위치
# dist = 각 친구가 1시간 동안 이동할 수 있는 거리
from itertools import permutations

def solution(n, weak, dist):
    INF = 99999999
    answer = INF
    weak_point = weak + [w+n for w in weak] # 원형의 그림을 펴서 탐색하기 위해 2배로 늘림
    # 시작점
    for (idx, start) in enumerate(weak): # 시작지점을 취약지점 중 하나로 바꿔가면서 모든 경우를 탐색
        # 가능한 모든 케이스의 순열
        for dist_temp in permutations(dist): # 순열을 사용하여 순서를 바꿔가면서 모든 경우를 탐색
            count = 1
            pos = start # 취약 지점
            for point in dist_temp:
                pos += point # 이동
                if pos >= weak_point[idx + len(weak) - 1]: # 한 바퀴 돈 경우
                    answer = min(answer, count)
                else:
                    pos = [w for w in weak_point if w > pos][0] # 다음 시작 지점을 다음 취약 지점으로 지정
                    count += 1
    return -1 if answer == INF else answer
print(solution(12,[1, 5, 6, 10],[1, 2, 3, 4]))