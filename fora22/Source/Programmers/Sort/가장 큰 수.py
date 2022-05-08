'''
Sort
참고
https://jokerldg.github.io/algorithm/2021/05/06/most-big-number.html
'''
def solution(numbers):
    numbers = list(map(str, numbers))
    # numbers의 원소가 1000이하이므로 1자리 숫자일 경우를 대비해 3제곱 시켜줌
    # 문자열 비교는 Ascii 코드로 비교하기 때문에 앞자리 숫자가 큰 순으로 sort됨
    # 예: '3' > '30' -> '333' > '303030' => 앞자리는 '3'으로 같고 그 다음 두번째가 '3'과 '0' 비교이므로 '3'이 더 크게 됨
    numbers.sort(key=lambda x: x*3, reverse=True)

    answer = str(int(''.join(numbers)))
    return answer


n = [[6, 10, 2], [3, 30, 34, 5, 9], [666,667,660,656]]

for i in range(3):
    print(solution(n[i]))
    # break