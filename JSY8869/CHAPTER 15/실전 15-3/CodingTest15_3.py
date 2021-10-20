def binary_search(house, N, C): # 이진탐색!
    start = 1
    end = house[-1] - house[0]
    count = 0
    old = house[0]
    while start <= end:
        mid = (start + end) // 2   # mid = 최소 간격

        for i in range(1,N):
            if house[i] >= old+mid:
                count+=1
            else:
                old = house[i]

        if count>=C: # 공유기를 더 설치했거나 딱 맞게 설치한 경우
            start = mid + 1
            result = mid
        else: # 공유기를 덜 설치한 경우
            end = mid - 1

    return result



N, C = map(int,input().split())
house = []
for _ in range(N):
    house.append(int(input()))
print(binary_search(sorted(house),N, C))