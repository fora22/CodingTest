from collections import deque

def get_next_pos(pos, board):
    next_pos = []
    (x1, y1), (x2, y2) = pos
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    dt = [-1, 1]

    # 상하좌우 이동
    for i in range(4):
        if board[x1+dx[i]][y1+dy[i]] == 0 and board[x2+dx[i]][y2+dy[i]] == 0:
            next_pos.append({(x1+dx[i], y1+dy[i]), (x2+dx[i], y2+dy[i])})

    # 세로 -> 가로 회전
    if y1 == y2:
        for i in dt:
            if board[x1][y1+i] == 0 and board[x2][y2+i] == 0:
                next_pos.append({(x1, y1), (x1, y1+i)})
                next_pos.append({(x2, y2), (x2, y2+i)})

    # 가로 => 세로 회전
    elif x1 == x2:
        for i in dt:
            if board[x1+i][y1] == 0 and board[x2+i][y2] == 0:
                next_pos.append({(x1, y1), (x1+i, y1)})
                next_pos.append({(x2, y2), (x2+i, y2)})

    # 다음에 갈 수 있는 위치들 모두 반환
    return next_pos
    

def solution(board):
    n = len(board)
    new_board = [[1]*(n+2) for _ in range(n+2)]

    for i in range(1, n+1):
        for j in range(1, n+1):
            new_board[i][j] = board[i-1][j-1]

    q = deque()
    pos = {(1, 1), (1, 2)} # 시작 지점
    visited = [] # 방문한 곳
    q.append((pos, 0))
    visited.append(pos)
    while q:
        pos, cost = q.popleft()
        # 종점에 도착하면 종료
        if (n, n) in pos:
            return cost
        for next_pos in get_next_pos(pos, new_board):
            if next_pos not in visited:
                visited.append(next_pos)
                q.append((next_pos, cost+1))