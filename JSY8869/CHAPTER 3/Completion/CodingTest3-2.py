N, M, K = map(int,input().split())
N_List = list(map(int,input().split()))

Result = 0

N_List.sort(reverse = True) # 내림차순 정렬

while (M != 0):
    for i in range(K):
        Result += N_List[0]
        M -= 1
    Result += N_List[1]
    M -= 1
print(Result)