import java.util.*;
public class CodingTest3_2_Java_Review{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        short N = scanner.nextShort(); // 공백 구분 입력
        short M = scanner.nextShort();
        short K = scanner.nextShort();
        int[] N_List = new int[N];
        for (int i = 0; i < N; i++){ // for문을 사용하여 공백 구분 입력
            N_List[i] = scanner.nextInt();
        }
        Arrays.sort(N_List); // 오름차순 정렬
        System.out.println((N_List[N-1] * (M - (M / K)) + (N_List[N-2] * (M / K))));
    }
}