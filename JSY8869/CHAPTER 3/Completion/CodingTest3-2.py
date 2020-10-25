N, M, K = map(int,input().split())
N_List = list(map(int,input().split()))

Result = 0

N_List.sort(reverse = True) # 내림차순 정렬

while True:
    for i in range(K):
        Result += N_List[0]
        M -= 1
        if M == 0:
            break
    if M == 0:
        break
    Result += N_List[1]
    M -= 1
    if M == 0:
        break

print(Result)