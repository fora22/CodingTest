import java.util.*;

public class CodingTest3_3{
    public static void main(String[] args){
        Find_Card_Game Card_Game = new Find_Card_Game();
        Card_Game.Random_List(); // Test Case 생성
        Card_Game.Find_Result(); // 결과값 찾기, 출력
    }
}

class Test_case{
    Random random = new Random();
    int M = random.nextInt(100) + 1;
    int K = random.nextInt(100) + 1;
    int[][] MK_List = new int[M][K];

    void Random_List(){
        for(int i = 0; i < M; i++)
            for(int j = 0; j < K; j++)
                MK_List[i][j] = random.nextInt(10000) + 1;
        // for(int i = 0; i < M; i++)
        //     System.out.println(Arrays.toString(MK_List[i])); // Test용
    }
}

class Find_Card_Game extends Test_case{
    int[] Result = new int[M];

    void Find_Result(){
        for(int i = 0; i < M; i++){
            Arrays.sort(MK_List[i]);
            Result[i] = MK_List[i][0];} // 각 행의 최소값을 저장
        Arrays.sort(Result);
        System.out.println(Result[M-1]); // 각 행의 최소값 중 최대값을 출력
    }
}