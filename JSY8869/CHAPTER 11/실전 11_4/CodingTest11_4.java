import java.util.*;
class CodingTest11_4{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int i = 1;
        int[] coin_value_list = new int[N];
        for(int y = 0; y < N; y++){
            coin_value_list[y] = scanner.nextInt();
        }
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