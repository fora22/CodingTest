# 통과함!!

def solution(n, arr1, arr2):
    map_  = [[0] * n for x in range(n)]
    for i in range(len(arr1)):
        wall_1 = format(arr1[i], 'b').zfill(n)
        wall_2 = format(arr2[i], 'b').zfill(n)

        for j in range(n):
            if (wall_1[j] == '0') and (wall_2[j] == '0'):
                map_[i][j] = ' '
            else:
                map_[i][j] = '#'

    answer = []
    for idx in range(n):
        temp = ''.join(map_[idx])
        answer.append(temp)

    return answer


nn = [5, 6]
a1 = [[9, 20, 28, 18, 11], [46, 33, 33 ,22, 31, 50]]
a2 = [[30, 1, 21, 17, 28], [27 ,56, 19, 14, 14, 10]]

for i in range(2):
    print(solution(nn[i], a1[i], a2[i]))
