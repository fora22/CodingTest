import java.util.Random;

class CodingTest3_3{
    public static void main(String[] args){
        Test_case mm = new Test_case();


    }
}


class Test_case{
    Random random = new Random();
    int M = random.nextInt(100) + 1;
    int K = random.nextInt(100) + 1;
    int[][] MK_List = new int[M][K];

    void Random_List(){
        for(int i = 0; i < M; i++){
            for(int j = 0; i < K; i++){
                MK_List[i][j] = random.nextInt(10000) + 1;
            }

        }
    }
}