import java.util.*;
class CodingTest11_3{
    public static void main(String[] args){
        String S = "00011001011";
        String[] S_list_temp = S.split("");
        int[] S_list = new int[S_list_temp.length];
        for(int i = 0; i < S_list.length; i++){
            S_list[i] = Integer.parseInt(S_list_temp[i]);
        }
        int count_0 = 0;
        int count_1 = 0;
        if (S_list[0] == 0) {
            count_0 += 1;
        }
        else {
            count_1 += 1;
        }
        for(int i = 0; i < S_list.length-1; i++){
            if(S_list[i] != S_list[i+1]){
                if(S_list[i+1] == 0)
                    count_0 += 1;
                else{
                    count_1 += 1;
                }
            }
        }
        System.out.println(Math.min(count_0, count_1));
    }
}