class CodingTest8_3 {
    public static void main(String[] args){
        int[] N = {4, 5, 6};
        int[][] list = {{1, 3, 1, 4}, {9, 3, 12, 15, 2}, {9, 3, 11, 5, 5, 9}};
        int result;
        for(int k = 0; k < 3; k++){       // test_case 3가지 차례대로 실행
            result = list[k][0] + list[k][2];
            for(int i = 0; i < N[k]-2; i++){         // 0 ~ N-2까지
                for(int j = i+2; j < N[k]; j++){       // i+2 ~ N까지
                    if(result < list[k][i]+list[k][j]){      // 최댓값 갱신
                        result = list[k][i]+list[k][j];
                    }
                }
            }
            System.out.println(result);
        }
    }
}