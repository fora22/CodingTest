import java.util.*;
class CodingTest11_4{
    public static void main(String[] args){
        int N = 4;
        int i = 1;
        int[] coin_value_list = {1,2,3,6};
        Arrays.sort(coin_value_list);
        for(int x : coin_value_list){
            if (i < x){
                break;
            }
            i += x;
        }
        System.out.println(i);
    }
}