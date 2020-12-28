import java.util.*;
class CodingTest5_3_N_DFS{
    public static void main(String[] args){
        int N = 4;
        int M = 5;
        int result = 0;
        int i_temp;
        int j_temp;
        int[][] space = {{0,1,0,0,1},{1,0,1,1,0},{1,1,1,1,0},{1,0,0,0,1},{1,1,0,0,1},{1,1,1,1,0}};
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                i_temp = i;
                j_temp = j;
                if (space[i][j] == 0){              // 현재 위치가 공간이 있다면 그 공간을 한칸씩 이동하면서 탐색
                    space[i][j] = 1;
                    result += 1;
                    for(int k = 0; k < 4; k++){              // 4방향을 탐색하면서 빈공간이 보일때마다 한칸씩 이동하면서 탐색함 (두더지를 생각하였음)
                        if(i+dx[k] != -1 && i+dx[k] != N && j+dy[k] != -1 && j+dy[k] != M){
                            if(space[i+dx[k]][j+dy[k]] == 0){
                                i = i+dx[k];
                                j = j+dy[k];
                                k = 0;
                                space[i][j] = 1;
                            }
                        }
                    }
                }
                i = i_temp;              // 공간 탐색이 끝난 후 다시 원래의 위치부터 다시 탐색 시작
                j = j_temp;
            }
        }
        System.out.println(result);   
    }
}

