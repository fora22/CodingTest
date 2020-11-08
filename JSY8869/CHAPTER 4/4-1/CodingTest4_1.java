import java.util.*;
class CodingTest4_1{
    public static void main(String[] args){
        UDLR temp = new UDLR();
        temp.make_plan(); // 랜덤으로 계획서 생성
        for(int j = 0; j < temp.Number_0f_Moves; j++){
            temp.Where_To_Go(j); // 계획서에 따라 차례대로 이동
        }
        System.out.printf("%d %d", temp.Result[0], temp.Result[1]);
    }
}

class UDLR{
    Random random = new Random();
    int[] Result = {1,1};
    int N = random.nextInt(100)+1;
    int Number_0f_Moves = random.nextInt(100)+1;
    char[] plan = new char[Number_0f_Moves];

    void make_plan(){
        for (int i = 0; i < Number_0f_Moves; i++)
            plan[i] = "UDLR".charAt(random.nextInt("UDLR".length()));
    }
    void Where_To_Go(int j){
        switch(plan[j]){
            case 'U':{
                if (Result[0] != 1){
                    Result[0]--;
                }
                break;
            }
            case 'D':{
                if (Result[0] != N){
                    Result[0]++;
                }
                break;
            }
            case 'L':{
                if (Result[1] != 1){
                    Result[1]--;
                }
                break;
            }
            case 'R':{
                if (Result[1] != N){
                    Result[1]++;
                }
                break;
            }
        }
    }
}