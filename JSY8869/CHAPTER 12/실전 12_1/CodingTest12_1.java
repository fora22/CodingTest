import java.util.*;

class CodingTest12_1{
    public static void main(String[] args){
        int N = 123401;
        String s = String.valueOf(N);
        int left_result = 0;
        int right_result = 0;
        for(int i = 0; i < s.length()/2; i++){
            left_result += s.charAt(i);
        }
        for(int i = s.length()/2; i < s.length(); i++){
            right_result += s.charAt(i);
        }
        if(left_result == right_result){
            System.out.println("LUCKY");
        }
        else{
            System.out.println("READY");
        }
    }
}