import java.util.*;
class CodingTest11_5{
    public static void main(String[] args){
        int N = 5;
        int M = 8;
        int[] K = {1, 5, 4, 3, 2, 4, 5, 2};
        int temp = 0;
        Arrays.sort(K);
        int result = factorial(M)/(factorial(M-2)*2);
        for(int i = 1; i < M; i++){
            if(K[i-1] == K[i]){
                temp += 1;
            }
            if(i == M-1 || K[i-1] != K[i]) {
                if(temp != 0){
                    result = result - factorial(temp);
                    temp = 0;
                }
            }
        }
        System.out.println(result);
    }

    public static int factorial(int x){
        int result = 1;
        for(int i = 1; i <= x; i++){
            result = result*i;
        }
        return result;
    }
}