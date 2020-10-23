# SW Expert Academy
[문제 1206.](https://swexpertacademy.com/main/code/problem/problemList.do)

`freopen()`함수로 쉽게 input.txt 로부터 테스트 케이스를 받을 수 있다.

# 해결
vector에 building 높이를 넣고 for문으로 하나씩 돈다.
if문으로 현재 빌딩 높이가 양 옆 2칸 빌딩 높이보다 크다면, 양 옆 2칸 중 제일 높은 빌딩 높이를 구하여 현재 빌딩 높이에서 빼고 결과값인 `viewPointSum`에 저장한다.
