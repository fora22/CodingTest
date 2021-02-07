import java.util.*;

public class CodingTest9_2{
    public static void main(String[] args){
        CodingTest9_2 temp = new CodingTest9_2();
        int[] N = {5, 4, 4};
        int[] M = {7, 5, 4};
        int[] X = {4, 3, 2};
        int[] K = {5, 4, 3};
        int[][] a = {{1,1,1,2,3,3,4}, {1,1,1,2,3}, {1,2,3,4}};
        int[][] b = {{2,3,4,4,4,5,5}, {2,3,4,3,4}, {2,4,1,3}};
        for(int z = 0; z < 3; z++){
            temp.future_city(N[z], M[z], X[z], K[z], a[z], b[z]);
        }
    }
    public void future_city(int N, int M, int X, int K, int[] a, int[] b) {
        int INF = 1000000000;
        int[][] AL = new int[N+1][N+1];

        for (int v = 0; v <= N; v++) {
            Arrays.fill(AL[v], INF);      // 전체 무한으로 초기화
        }
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if (j == k){    // 자기 자신으로 가는 경우 = 0
                    AL[j][k] = 0;
                }
            }
        }
        for(int i = 0; i < M; i++){  // 가는 방향, 오는 방향 모두 거리는 1
            AL[a[i]][b[i]] = 1;
            AL[b[i]][a[i]] = 1;
        }

        for(int l = 1; l <= N; l++){
            for(int q = 1; q <= N; q++){
                for(int w = 1; w <= N; w++){
                    AL[q][w] = Math.min(AL[q][w], AL[q][l] + AL[l][w]); // 바로 가는 것과 거쳐서 가는 것 중 더 빠른 방법 저장
                }
            }
        }
        if(AL[1][K] >= INF || AL[K][X] >= INF){
            System.out.println("-1");
        }
        else{
            System.out.println(AL[1][K] + AL[K][X]);
        }
    }
}