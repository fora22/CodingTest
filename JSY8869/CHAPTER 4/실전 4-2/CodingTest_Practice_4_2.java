import java.util.*;
class CodingTest_Practice_4_2{
    public static void main(String[] args){
        Random random = new Random();
        int N = random.nextInt(3) + 1;
        int M = random.nextInt(50) + 1;
        int d = random.nextInt(4);
        int A, B;
        int count = 0;
        int[][] map = new int[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if (i == N-1 || i == 0 || j == M-1 || j == 0){  // 외곽 조건
                    map[i][j] = 1;
                    continue;
                }
                map[i][j] = random.nextInt(2); // 맵 생성

            }
        }
        System.out.println(Arrays.deepToString(map));
        do{
            A = random.nextInt(N) + 1;
            B = random.nextInt(M) + 1;
        }while(map[A][B] != 0);
    }
}