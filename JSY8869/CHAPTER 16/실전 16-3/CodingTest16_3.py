def main(N, TiPi):
    Ti = []
    Pi = []
    for i in range(len(TiPi)):
        Ti.append(int(TiPi[i][0]))
        Pi.append(int(TiPi[i][1]))
    d = [0 for _ in range(N+1)]
    for i in range(N-1, -1, -1):
        if i + Ti[i] > N:
            d[i] = d[i+1]
        else:
            d[i] = max(d[i+1], Pi[i] + d[i + Ti[i]])

    return d[0]



# TEST

file = open("CHAPTER 16/실전 16-3/input.txt", "r")
result = []
N = []
for i in range(4):
    TiPi = []
    line = int(file.readline().strip())
    N.append(line)
    for _ in range(line):
        TiPi.append(file.readline().strip().split())
    result.append(int(file.readline().strip()))

    if int(main(N[i], TiPi)) == result[i]:
        print("O")
    else:
        print("X")
        break
    
file.close()