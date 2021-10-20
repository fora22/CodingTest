# N = int(input())     # 이진탐색 미사용
# N_List = list(map(int,input().split()))
# result = -1
# for idx, val in enumerate(N_List):
#     if(idx == val):
#         result = val
#         break
# print(result)

def binary_search(array, start, end): # 이진탐색!
    while start <= end:
        mid = (start + end) // 2

        if array[mid] == array.index(array[mid]): # 중간 값과 중간 값의 인덱스가 같으면 종료
            return mid # 함수를 끝내버린다.
        elif array[mid] < array.index(array[mid]): # 중간 값보다 중간 값의 인덱스가 더 큰 경우
            start = mid + 1
        else:
            end = mid -1 # 중간 값보다 중간 값의 인덱스가 더 작은 경우

    return -1 # 고정점이 없는 경우

N = int(input())
N_List = list(map(int,input().split()))
print(binary_search(N_List, 0, N-1))