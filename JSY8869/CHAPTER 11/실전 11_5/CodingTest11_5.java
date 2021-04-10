import java.util.*;
class CodingTest11_5{
    public static void main(String[] args){
        int N = 8;
        int M = 5;
        int[] K = {1, 5, 4, 3, 2, 4, 5, 2};
        int result = 0;
        Arrays.sort(K);
        int temp;
        for(int j = 0; j < N-1; j++){
            temp = K[j];
            for(int i = j+1; i < N; i++){
                if(temp != K[i]){
                    result++;
                }
            }
        }
        System.out.println(result);
    }
}