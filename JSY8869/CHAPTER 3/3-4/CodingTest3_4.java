import java.util.*;

public class CodingTest3_4 {
    public static void main(String[] args){
        Until_one temp = new Until_one();
        temp.select();
    }
}

class Until_one{
    Random random = new Random();
    int N = random.nextInt(99999) + 2;
    int K = random.nextInt(N-1) + 2;
    long count = 0;
    void select(){
        System.out.printf("N = %d K = %d", N, K);
        if (N == 1){
            System.out.println(count);
        }
        else{
            if (N % K == 0){
                select_two();
            }
            else{
                select_one();
            }
        }
    }
    void select_one(){
        N -= 1;
        count +=1;
        select();
    }
    void select_two(){
        N = N / K;
        count += 1;
        select();
    }
}