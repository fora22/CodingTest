import java.util.*;

public class CodingTest3_4 {
    public static void main(String[] args){
        Until_one temp = new Until_one();
        while(temp.N != 1){
            temp.select();
        }
        System.out.println(temp.count);
    }
}

class Until_one{
    Random random = new Random();
    int N = random.nextInt(99999) + 2;
    int K = random.nextInt(N-1) + 2;
    long count = 0;
    void select(){
        if (N % K == 0){
            N = N / K;
            count += 1;
        }
        else{
            N -= 1;
            count +=1;
        }
    }
}