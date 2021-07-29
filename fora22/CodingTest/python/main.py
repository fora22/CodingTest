# import os, sys
# dirName = os.getcwd()
# sys.stdin = open(dirName + "\\input.txt", 'r')

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

class snakeGame():
    def __init__(self):
        self.dX = [0, 1, 0, -1]  # E, S, W, N
        self.dY = [1, 0, -1, 0]  # E, S, W, N

    def turn(dIndex, c):
        if c == "L":
            dIndex = (dIndex - 1) % 4
        else:
            dIndex = (dIndex + 1) % 4
        return dIndex


    def delTail(q):
        q.pop(0)
        return q
        
    def gameStart(headX, headY, direc):
        timeCount = 1
        snakeWay = [[1,1]]   
        for x, c in movement:       
            timeCount, direc, snakeWay = snakeMove(x, c, snakeWay, headX, headY, direc, timeCount)
        
        timeCount, direc, snakeWay = snakeMove(x, c, snakeWay, headX, headY, direc, timeCount)
        
        return timeCount

    def snakeMove(x_, c_, snakeWay_, head_X, head_Y, direction, timeCount_):
        while True:
            head_X += dX[direction]
            head_Y += dY[direction]

            if (head_X > N) or (head_Y > N) or (head_X < 1) or (head_Y < 1):
                return timeCount_, direction, snakeWay_
            
            if ([head_X, head_Y] in apple):
                apple.remove([head_X, head_Y])
            elif ([head_X, head_Y] in snakeWay_):
                return timeCount_, direction, snakeWay_
            else:
                snakeWay_ = delTail(snakeWay_)

            snakeWay_.append([head_X, head_Y])

            
            # if snakeMap[head_X][head_Y] == 1:
            #     snakeMap[head_X][head_Y] = 0
            # elif snakeMap[head_X][head_Y] == 2:
            #     break
            # else:
            #     snakeMap[tail_X][tail_Y] = 0
            #     tail_X += dX[direction]
            #     tail_Y += dY[direction]
            
            # snakeMap[head_X][head_Y] = 2
            
            timeCount_ += 1

            if timeCount_ == x_:
                direction = turn(direction, c_)
                break
        return timeCount_, direction, snakeWay_


initX, initY, initDriection = 1, 1, 0  # start position, direction
print(gameStart(initX, initY, initDriection ))