import java.util.*;
class CodingTest_Practice_4_2{
    public static void main(String[] args){
        Random random = new Random();
        int N = random.nextInt(47) + 4;        // 맵의 세로 크기
        int M = random.nextInt(50) + 1;        // 맵의 가로 크기
        int d = random.nextInt(4);            // 처음 방향
        int A, B;
        int count = 0;
        int[][] map = new int[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if (i == N-1 || i == 0 || j == M-1 || j == 0){  // 외곽 조건
                    map[i][j] = 1;
                    continue;}
                map[i][j] = random.nextInt(2);}} // 맵 생성
        do{
            A = random.nextInt(N - 2) + 1;
            if (M-2 <= 0){
                B = random.nextInt(M);}
            else{
                B = random.nextInt(M - 2) + 1;  }
        }while(map[A][B] != 0);
        map[A][B] = 2;
        main : while(true){                             //  왼쪽으로 돌면서 이동 가능 시 이동
            middle_for : for(int k = 0; k < 4; k++){
                switch(d){
                    case 0:
                    d = 3;
                    if(map[A][B-1] == 0){             //  왼쪽이 육지면 이동
                        map[A][B-1] = 2;
                        count += 1;
                        B -= 1;
                        break middle_for;}
                    case 1:
                    d = 0;
                    if(map[A-1][B] == 0){
                        map[A-1][B] = 2;
                        count += 1;
                        A -= 1;
                        break middle_for;}
                    case 2:
                    d = 1;
                    if(map[A][B+1] == 0){
                        map[A][B+1] = 2;
                        count += 1;
                        B += 1;
                        break middle_for;}
                    case 3:
                    d = 2;
                    if(map[A+1][B] == 0){
                        map[A+1][B] = 2;
                        count += 1;
                        A += 1;
                        break middle_for;}
                }
            }
            if (map[A+1][B] != 0 && map[A-1][B] != 0 && map[A][B+1] != 0 && map[A][B-1] != 0){       // 4방향 모두 갈 수 없는 경우
                switch(d){
                    case 0:
                    if(map[A+1][B] == 2){           // 뒤가 지나온 길인 경우 뒤로 가기
                        A += 1;
                        break;}
                    else{                      // 뒤가 바다인 경우 종료
                        break main;}
                    case 1:
                    if(map[A][B-1] == 2){
                        B -= 1;
                        break;}
                    else{
                        break main;}
                    case 2:
                    if(map[A-1][B] == 2){
                        A -= 1;
                        break;}
                    else{
                        break main;}
                    case 3:
                    if(map[A][B+1] == 2){
                        B += 1;
                        break;}
                    else{
                        break main;}}}}
        System.out.println(count);  // 결과 출력
    }
}