class CodingTest5_3{
    int N;
    int M;
    int[][] space;
    public static void main(String[] args){
        CodingTest5_3 T = new CodingTest5_3();
        T.N = 4;
        T.M = 5;
        int result = 0;
        int[][] space = {{0,1,0,0,1},{1,0,1,1,0},{1,1,1,0,0},{1,0,0,0,1}};
        for(int i = 0; i < T.N; i++){
            for(int j = 0; j < T.M; j++){
                if (space[i][j] == 0){
                    T.DFS(space,i,j);
                    result += 1;
                }
            }
        }
        System.out.println(result);   
    }
    void DFS(int[][] space, int i, int j){
        if(i == -1 || i == N || j == -1 || j == M){
            return;
        }
        if (space[i][j] == 0){
            space[i][j] = 1;
        }
        else{
            return;
        }
        DFS(space, i-1, j);
        DFS(space, i+1, j);
        DFS(space, i, j-1);
        DFS(space, i, j+1);
    }
}