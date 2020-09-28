# Coding_Test
for coding test with c++

# 조합 구하기

 { {"yellow_hat", "headgear"} ,{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };

컨테이너(key, value)에서 중복없이 총 조합의 수를 구하는 방식은 다음과 같다

각 key값에 따른 count 수를 세어 size라는 컨테이너에 넣는다(index가 key라고 가정).

size[n(1), n(2), n(3), ... , n(n)]

1개 : n(1) + n(2) + n(3) + ... + n(n)

2개 : n(1) * (n(2) + n(3) + ... n(n)) + n(2) * (n(3) + ... + n(n)) + ... + n(n-1) * n(n)

3개 : (n(1) * n(2)) * (n(3) + n(n)) + (n(2) * n(3)) * (n(4) + ... + n(n)) + (n(n-2) * n(n-1)) * (n(n))

...

n개 : n(1) * n(2) * n(3) * ... * n(n)

