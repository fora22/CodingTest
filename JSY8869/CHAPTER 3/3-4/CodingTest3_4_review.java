import java.util.*;

public class CodingTest3_4_review {
    public static void main(String[] args){
        Random random = new Random();
        int N = random.nextInt(99999) + 2;
        int K = random.nextInt(N-1) + 2;
        int count = 0;
        while(N != 1){          // N이 1이 될 때까지 반복
            if (N % K == 0){     // N이 K로 나누어 떨어지면 2번 실행
                N = N / K;
                count += 1; 
            }
            else{               // N이 K로 나누어 떨이지지 않으면 1번 실행
                N -= 1;
                count +=1;
            }
        }
        System.out.println(count);
    }
}