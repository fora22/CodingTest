from itertools import permutations as permu

def is_prime(n: int) -> bool:
    # 소수인지 판별해주는 함수
    if n < 2:
        return False 
    if n in (2, 3): 
        return True 
    if n % 2 is 0 or n % 3 is 0: 
        return False 
    if n < 9: 
        return True 
    k, l = 5, n**0.5 
    while k <= l: 
        if n % k is 0 or n % (k+2) is 0: 
            return False 
        k += 6 
    return True

def primes_up_to_good(n:int):
    # n까지의 숫자 중 소수 집합을 반환해주는 함수, 여기서는 사용 안함
    # 에라토스테네스의 체
    seive = [False, False] + [True] * (n - 1) 
    for k in range(2, int(n ** 0.5 + 1.5)): 
        if seive[k]: 
            seive[k*2::k] = [False] * ((n - k) // k) 
    return [x for x in range(n+1) if seive[x]]

def solution(numbers):
    n_len = len(numbers)
    numbers = list(numbers)
    permu_list = []
    for num_len in range(1, n_len + 1):
        permu_list += list(permu(numbers, num_len))
    permu_list = [''.join(x) for x in permu_list]
    permu_list = list(set(permu_list))
    decimals = list(set([int(x) for x in permu_list if is_prime(int(x))]))
    answer = len(decimals) 
    return answer

n = ["17", "011"]

for i in range(2):
    print(solution(n[i]))