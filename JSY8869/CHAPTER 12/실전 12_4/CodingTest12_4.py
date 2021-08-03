from collections import deque

n = int(input()) # 맵 크기
k = int(input()) # 사과 개수
board = [[0]*n for _ in range(n)] # 맵 생성
for i in range(k):
    row,col = map(int,input().split()) # 사과 위치 입력
    board[row-1][col-1] = 1 # 사과가 있는 곳 맵에 저장

l = int(input()) # 방향 변환 횟수
rotate_arr = deque()
for i in range(l):
    rot_time,rot = input().split() # 회전 시간, 회전 방향 입력
    rotate_arr.append([int(rot_time),rot]) # 회전 시간, 회전 방향 deque에 추가

dcol = (1,0,-1,0) # 가로
drow = (0,-1,0,1) # 세로

snake = deque([[0,0]]) # 뱀의 위치
time = 0
rot_time,rot = rotate_arr.popleft() # 방향 변경 시간, 변경 방향
direction = 0 # 현재 방향

while True:
    time += 1
    new_x,new_y = snake[0][0]+drow[direction],snake[0][1] + dcol[direction] # 머리 이동

    snake.appendleft([new_x,new_y]) # 머리 방향 길이+1
    if board[new_x][new_y]: # 사과가 있으면
        board[new_x][new_y] = 0 # 사과 제거
    else : # 사과가 없으면
        snake.pop() # 꼬리 삭제

    if new_x<0 or new_x>n-1 or new_y<0 or new_y>n-1 : # 맵 밖으로 나가는지 확인
        break

    for i in range(len(snake)): # 몸통과 부딪히는지 확인
        if [new_x,new_y] == snake[i]:
            break

    if time == rot_time : # 방향을 변경할 시간인 경우
        if rot == 'L': # 좌회전
            if direction == 3:
                direction = 0
            else:
                direction += 1
        else:
            if direction == 0:
                direction = 3
            else:
               direction -= 1

        if len(rotate_arr)>0 :
            rot_time,rot = rotate_arr.popleft()

print(time)