def solution(numbers):
    length = len(numbers)
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x: x*3, reverse=True)

    answer = ''.join(numbers)
    return answer

n = [[6, 10, 2], [3, 30, 34, 5, 9]]

for i in range(2):
    print(solution(n[i]))
    # break