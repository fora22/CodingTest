# CodingTest3-1 거스름돈 (array 활용)

while True:
    N = int(input("거스름 돈을 입력하세요 : ")) # 입력 받는 거스름 돈
    Coin_Count = 0 # 거슬러 주어야 할 동전의 개수
    Coin_Value = [500,100,50,10] # 함수에서 사용 할 동전의 가격 리스트

    if N > 0 and N % 10 == 0:
        for coin in Coin_Value:
            Coin_Count += int(N/coin) # int로 선언하여 정수부분만 사용
            N = N % coin
            if N == 0:
                break # for문 종료
        break # while문 종료
    else:
        print("0보다 큰 10의 배수를 입력하세요.")
print("%d개의 동전이 필요합니다."%Coin_Count)