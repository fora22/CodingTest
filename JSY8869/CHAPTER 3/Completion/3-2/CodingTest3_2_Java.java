import java.util.*;
public class CodingTest3_2_Java {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        short N = scanner.nextShort(); // 공백 구분 입력
        short M = scanner.nextShort();
        short K = scanner.nextShort();
        int Result = 0;
        int[] N_List = new int[N];
        for (int i = 0; i < N; i++){ // for문을 사용하여 공백 구분 입력
            N_List[i] = scanner.nextInt();
        }
        Arrays.sort(N_List); // 오름차순 정렬
        while(M != 0){
            for(int j = 0; j < K; j++){
                Result += N_List[N-1];
                M -= 1;
            }
            Result += N_List[N-2];
            M -= 1;
        }
        System.out.printf("%d", Result); // 결과 출력
    }   
}