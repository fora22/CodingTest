import java.util.*;

class CodingTest4_1{
    public static void main(String[] args){
        Time temp = new Time();
    }
}

class Time{
    Time(){
        Random random = new Random();
        int N = random.nextInt(24);
        int count = 0;
        String three = "3";
        for(int i = 0; i < N; i++)
            for(int j = 0; j < 60; j++)
                for(int k = 0; k < 60; k++){
                    String itemp = Integer.toString(i);
                    String jtemp = Integer.toString(j);
                    String ktemp = Integer.toString(k);
                    if(itemp.equals(three) || jtemp.equals(three) || ktemp.equals(three))
                        count += count;
                    }
        System.out.println(count);
    }       
}