import sys
sys.stdin = open("input.txt", 'r')

N = int(input())

K = int(input())

apple = []
for i in range(K):
    aX, aY = map(int, input().split())
    apple.append([aX, aY])

L = int(input())

movement = [] # x, c
for i in range(L):
    t, d = input().split()
    movement.append([int(t), d])

dX = [0, 1, 0, -1]  # E, S, W, N
dY = [1, 0, -1, 0]  # E, S, W, N
direction = 0
def turn(dIndex, c):
    if c == "L":
        dIndex = (dIndex - 1) % 4
    else:
        dIndex = (dIndex + 1) % 4
    return dIndex

mapX = 0
mapY = 1

timeCount = 0
snake = [[1,1]]

# check

def check(time):
    snakeMap = [[0 for _ in range(N + 1)] for i in range(N + 1)]
    for ap in apple:
        
        snakeMap[ap[0]][ap[1]] = 1
    for sn in snake:
        snakeMap[sn[0]][sn[1]] = 2
    print(time)
    for sm in snakeMap:
        print(sm)
    print()
# game start

moveIndex = 0
x = movement[moveIndex][0]
c = movement[moveIndex][1]
movement.append([0, "D"])
while True:
    
    headX = snake[-1][mapX] + dX[direction]
    headY = snake[-1][mapY] + dY[direction]
    
    timeCount += 1

    if ([headX, headY] in apple):
        apple.remove([headX, headY])
    elif ([headX, headY] in snake):
        break
    else:
        snake.pop(0)

    snake.append([headX, headY])

    if (headX > N) or (headY > N) or (headX < 1) or (headY < 1):
        break
    check(timeCount)
    if timeCount == x:
        direction = turn(direction, c)
        moveIndex += 1
        x = movement[moveIndex][0]
        c = movement[moveIndex][1]

print(timeCount)
# check(timeCount)