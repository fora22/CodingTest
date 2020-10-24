# CodingTest3-1 거스름돈


def coin(N, Coin_Count ,Coin_Value):
        if N - Coin_Value > 0:
            N = N - Coin_Value
            Coin_Count += 1
            coin(N, Coin_Count ,Coin_Value)
        elif N - Coin_Value == 0:
            print("거스름 돈으로 줘야 할 동전의 최소 개수는 %d개 입니다."%(Coin_Count + 1))
        else:
            if Coin_Value == 500:
                Coin_Value = 100
            elif Coin_Value == 100:
                Coin_Value = 50
            elif Coin_Value == 50:
                Coin_Value = 10
            coin(N, Coin_Count ,Coin_Value)
while True:
    try:
        N = int(input("거스름 돈을 입력하세요 : "))
        Coin_Count = 0
        Coin_Value = 500
        coin(N, Coin_Count ,Coin_Value)
        break
    except:
        print("0보다 큰 10의 배수를 입력하세요.")


