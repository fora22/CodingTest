import java.util.*;
class CodingTest5_3_N_DFS{
    public static void main(String[] args){
        int N = 6;
        int M = 5;
        int result = 0;
        int i_temp;
        int j_temp;
        int[][] space = {{0,1,0,0,1},{1,0,1,1,0},{0,1,1,1,0},{0,0,1,1,1},{0,1,0,0,1},{0,1,1,1,0}};
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if (space[i][j] == 0){              // 현재 위치가 공간이 있다면 그 공간을 한칸씩 이동하면서 탐색
                    i_temp = i;
                    j_temp = j;
                    result += 1;
                    space[i][j] = 2;
                    while_1 : while(true){
                        for(int k = 0; k < 4; k++){              // 4방향을 탐색하면서 빈공간이 보일때마다 한칸씩 이동하면서 탐색함 (두더지를 생각하였음)
                            try{
                                if(space[i+dx[k]][j+dy[k]] == 0){
                                    i = i+dx[k];
                                    j = j+dy[k];
                                    k = -1;
                                    space[i][j] = 2;
                                    for_1 : for(int t = 2; t < 4; t++){              // 4방향을 탐색하면서 빈공간이 보일때마다 한칸씩 이동하면서 탐색함 (두더지를 생각하였음)
                                        try{
                                            if(space[i+dx[t]][j+dy[t]] == 0){
                                                space[i+dx[t]][j+dy[t]] = 2;
                                                break for_1;
                                            }
                                        }catch(Exception e){
                                            ;
                                        }
                                    }
                                }
                            }catch(Exception e){
                                ;
                            }
                        }
                        break while_1;
                    }
                    i = i_temp;
                    j = j_temp;
                }
            }
        }
        System.out.println(result);   
    }
}

