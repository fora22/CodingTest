import java.util.*;
class CodingTest6_4{
    public static void main(String [] args){
        Random random = new Random();
        int N = random.nextInt(100000)+1;
        int K = random.nextInt(N);
        int temp;
        long sum = 0;
        int[] A_list = new int[N];
        int[] B_list = new int[N];
        for(int k = 0; k < N; k++){
            A_list[k] = random.nextInt(10000000);
            B_list[k] = random.nextInt(10000000);
        }


        for(int i = 0; i < K; i++){
            Arrays.sort(A_list);          // 오름차순 정렬
            Arrays.sort(B_list);

            if (A_list[0] < B_list[N-1]){       // A의 최소값, B의 최대값 비교
                temp = B_list[N-1];
                B_list[N-1] = A_list[0];
                A_list[0] = temp;
            }
        }
        for (int j = 0; j < A_list.length; j++) {     // 정렬이 완료된 A 배열의 원소들의 합
            sum = sum + A_list[j];
        }
        System.out.println(sum);
    }
}