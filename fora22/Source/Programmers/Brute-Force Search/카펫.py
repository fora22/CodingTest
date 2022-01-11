'''
Brute Force
참고
https://it-garden.tistory.com/361
'''
def solution(brown, yellow):
    answer = []
    block = brown + yellow
    
    for width in range(2, block + 1):
        if block % width == 0:
            height = block // width
            if (width - 2) * (height - 2) == yellow and width >= height:
                answer = [width, height]
                break
    return answer

b = [10, 8, 24]
y = [2, 1, 24] 
for i in range(3):
    print(solution(b[i], y[i]))