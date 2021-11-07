def main(N,Combat_Power):
    if int(Combat_Power[0]) > int(Combat_Power[1]):
        for i in range(1, N-1):
                if int(Combat_Power[i]) > int(Combat_Power[i+1]) and int(Combat_Power[i-1]) > int(Combat_Power[i]):
                    pass
                else:
                    Combat_Power.remove(Combat_Power[i])
                    return main(N-1, Combat_Power)
    return N



file = open("CHAPTER 16/실전 16-4/input.txt", "r")
Combat_Power = []
N = int(file.readline().strip())
Combat_Power = file.readline().strip().split()
result = int(file.readline().strip())

if N - int(main(N, Combat_Power)) == result:
    print("O")
else:
    print("X")
    
file.close()