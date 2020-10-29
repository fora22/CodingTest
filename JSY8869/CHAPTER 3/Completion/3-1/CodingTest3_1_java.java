// CodingTest3-1 거스름돈 (Java 활용)

import java.util.*; // 변수의 값을 입력받기 위해 사용

public class CodingTest3_1_java{
	public static void main(String[] agrs){
		System.out.printf("거스름돈을 입력하세요 : ");
		Scanner scanner = new Scanner(System.in); 
		int N = scanner.nextInt(); // int형으로 로 값을 받음
		int Coin_Count = 0;
		int[] Coin_Value = {500,100,50,10}; // array 선언방법

		for(int Coin : Coin_Value)
		{
			Coin_Count = Coin_Count + (N/Coin); // Coin_Count 변수가 int로 선언되었기 때문에 소수점X
			N = N % Coin;
		}
		System.out.printf("거슬러 주어야 할 동전의 개수는 %d개 입니다.",Coin_Count);
	}
}