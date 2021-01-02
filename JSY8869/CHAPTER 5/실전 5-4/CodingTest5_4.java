import java.util.*;
class CodingTest5_4{
    public static void main(String[] args){
        int[] N_LIST = {5,6,7,4};
        int[] M_LIST = {6,5,7,4};
        int[][][] map_LIST = {{{1,0,1,0,1,0}, {1,1,1,1,1,1}, {0,0,0,0,0,1}, {1,1,1,1,1,1},{1,1,1,1,1,1}}, {{1,1,0,0,0},{1,1,1,1,0},{1,1,1,1,0},{0,1,0,0,0},{1,1,0,0,0},{1,1,1,1,1}},
        {{1,0,0,0,0,0,0},{1,1,1,1,1,1,1},{0,0,0,1,1,1,1},{1,1,1,1,0,0,0},{1,0,0,0,0,0,0},{1,1,1,1,1,1,1},{1,0,0,0,0,0,1}},{{1,1,1,1},{0,0,0,1},{1,1,1,1},{1,0,0,1}}};
        for(int time = 0; time < 4; time++){       // 4가지 testcase 실행
            int N = N_LIST[time];
            int M = M_LIST[time];
            int[][] map = map_LIST[time];
            boolean[][] visited = new boolean[N][M];
            int[] dx = {-1,1,0,0};
            int[] dy = {0,0,-1,1};
            int i = 0;
            int j = 0;
            int ij_list[] = {i,j};     // 시작 좌표
    
            Queue<int[]> q = new LinkedList<>();
            q.offer(ij_list);    // 초기 위치 QUEUE에 담음
            visited[i][j] = true; // 처음 위치 방문처리
    
            while(!q.isEmpty()){
                int location[] = q.poll();   // QUEUE에 담겨진 위치 값을 빼서 사용

                for(int k = 0; k<4; k++){        // 4방향 점검
                    int x = location[0] + dx[k];
                    int y = location[1] + dy[k];
                    if(x >= 0 && y >= 0 && x < N && y < M){
                        if(map[x][y] != 0 && !visited[x][y]){   // 방문하지 않은 벽이 아닌 공간 발견시 QUEUE에 담음
                            q.offer(new int[] {x,y});
                            visited[x][y] = true;         //  방문처리
                            map[x][y] = map[location[0]][location[1]] + 1;   // 해당 칸까지 이동한 횟수를 저장
                        }
                    }
                }
            }
            System.out.printf("%d번째 ", time+1);
            System.out.println(map[N-1][M-1]);
        }
    }
}