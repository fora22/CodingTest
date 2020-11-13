import java.util.*;
public class CodingTest4_2 {
    static void main(String[] args){
        Time temp = new Time();
        temp.Count_Three();
        temp.print_count();
    }
}

class Time{
    Random random = new Random();
    int N = random.nextInt(23);
    int count = 0;
    int[] three = {3,13,23,33,43,53,30,31,32,33,34,35,36,37,38,39};

    void Count_Three(){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < 60; j++)
                for(int k = 0; k < 60; j++)
                    for(int three_temp : three)
                        if (three_temp == i || three_temp == j||three_temp == k)
                            count += 1;
    }
    void print_count(){
        System.out.printf("%d",count);
    }
}
