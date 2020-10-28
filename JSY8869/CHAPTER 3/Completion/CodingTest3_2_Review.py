N, M, K = map(int,input().split())
N_List = list(map(int,input().split()))
N_List.sort(reverse = True) # 내림차순 정렬
print((N_List[0] * (M- int(M / K))) + (N_List[1] * int(M / K)))