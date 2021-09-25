# 처음 푼 버전
N = int(input())
Card_List = list(map(int, input().split()))
Card_List.sort()
result = Card_List[0] + Card_List[1]
for i in range(2,N):
    result += Card_List[i] + result
print(result)

# 런타임 에러 수정 버전(우선순위힙)
# import heapq
# result = 0
# N = int(input())
# Card_List = []
# for _ in range(N):
#     heapq.heappush(Card_List, int(input()))

# for i in range(N-1):
#     temp = heapq.heappop(Card_List)+heapq.heappop(Card_List)
#     heapq.heappush(Card_List, temp)
#     result += temp

# print(result)