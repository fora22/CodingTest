def solution(array, commands):
    answer = [0] * len(commands)

    for idx, command in enumerate(commands):
        i, j, k = command
        slice_array = array[i-1:j]
        slice_array.sort()
        k_number = slice_array[k-1]
        answer[idx] = k_number

    return answer

a = [1, 5, 2, 6, 3, 7, 4]
c = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]

print(solution(a, c))