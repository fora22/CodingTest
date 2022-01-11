'''
Sort
참고
https://jokerldg.github.io/algorithm/2021/05/06/most-big-number.html
'''
def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x: x*3, reverse=True)

    answer = str(int(''.join(numbers)))
    return answer

n = [[6, 10, 2], [3, 30, 34, 5, 9]]

for i in range(2):
    print(solution(n[i]))
    # break