import java.util.*;
class CodingTest8_2{
    public static void main(String[] args){
        Random random = new Random();
        int X = random.nextInt(30000)+1;
        int result[] = new int[X+1];
        
        for (int i = 2; i <= X; i++){     // Bottom-up 방식
            result[i] = result[i-1] + 1;          // 1을 뺐을 때를 기준으로 시작
            if(i % 2 == 0){
                result[i] = Math.min(result[i], result[i/2]+1);   // 2로 나눴을 때의 결과값의 최소 연산횟수와 그냥 값을 유지했을 때의 최소 연산횟수를 비교
            }
            if(i % 3 == 0){
                result[i] = Math.min(result[i], result[i/3]+1);   // 3로 나눴을 때의 결과값의 최소 연산횟수와 그냥 값을 유지했을 때의 최소 연산횟수를 비교
            }
            if(i % 5 == 0){
                result[i] = Math.min(result[i], result[i/5]+1);   // 5로 나눴을 때의 결과값의 최소 연산횟수와 그냥 값을 유지했을 때의 최소 연산횟수를 비교
            }
        }
        System.out.println(X);
        System.out.println(result[X]);
    }
}