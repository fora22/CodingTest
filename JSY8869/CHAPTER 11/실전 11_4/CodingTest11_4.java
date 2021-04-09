import java.util.*;
class CodingTest11_4{
    public static void main(String[] args){
        int N = 5;
        int i = 1;
        int[] coin_value_list = {3, 2, 1, 1, 9};
        Arrays.sort(coin_value_list);
        loop : while(true){
            for(int x : coin_value_list){
                if (i < x){
                    break loop;
                }
                i += x;
            }
        }
        System.out.println(i);
    }
}