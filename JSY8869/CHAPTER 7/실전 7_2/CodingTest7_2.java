import java.util.*;
class CodingTest7_2{
    public static void main(String[] args){
        Random random = new Random();
        int N = random.nextInt(1000000)+1;
        int[] N_array = new int[N];
        int M = random.nextInt(100000)+1;
        int[] M_array = new int[M];
        for(int j = 0; j < N; j++){
            N_array[j] = random.nextInt(1000000)+1;
        }
        for(int k = 0; k < M; k++){
            M_array[k] = random.nextInt(1000000)+1;
        }

        for(int i = 0; i < M_array.length; i ++){
            if(Arrays.binarySearch(N_array, M_array[i]) >= 0){         // N_array 내에서 M_array[i]와 일치하는 index의 위치를 알려줌, 없으면 음수값이 나옴
                System.out.print("YES ");
            }
            else{
                System.out.print("NO ");
            }
        }
    }
}