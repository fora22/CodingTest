import java.util.*;
class CodingTest8_5{
    int list = 10000;
    public static void main(String[] args){
        int N = 2;
        int M = 10000;
        Integer[] money_list = {2,3,7};
        int result = 0;
        CodingTest8_5 temp = new CodingTest8_5();
        Arrays.sort(money_list, Collections.reverseOrder());     // 가장 큰 화폐로 나누어 떨어지는 경우
        if(M % money_list[0] == 0){
            System.out.println(M / money_list[0]);
        }
        else{
            temp.money_arrange(M, money_list, result, temp.list);
            if(temp.list != 10000){
                System.out.println(temp.list);
            }
            else{
                System.out.println("-1");
            }
        }
    }
    public void money_arrange(int M, Integer[] money_list, int result, int list){
        if(M < 0){
            return;
        }
        if(M == 0){
            if(this.list > result){
                this.list = result;
            }
        }
        else{
            result = result + 1;
            for(int i = 0; i < money_list.length; i++){
                money_arrange(M - money_list[i], money_list, result, list);
            }
        }
    }
}