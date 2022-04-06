'''
Greedy
참고
https://wwlee94.github.io/category/algorithm/greedy/speed-enforcement-camera/
'''
def solution(routes):
    routes.sort(key=lambda x: x[1])
    camera = -30001
    answer = 0

    for route in routes:
        if camera < route[0]:
            answer += 1 
            camera = route[1]

    return answer

r = [[-20,-15], [-14,-5], [-18,-13], [-5,-3]]
print(solution(r))