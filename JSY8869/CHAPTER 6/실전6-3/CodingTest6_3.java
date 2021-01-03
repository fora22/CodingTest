class CodingTest6_3 {
    public static void main(String[] args){
        int N = 5;
        String[] name_list = {"나무늘보","사자","호랑이","달팽이","판다"};
        int[] grade_list = {50,100,60,45,10};

        for (int i =0; i < N-1 ; i++ ){
            for (int j = i+1; j < N ; j++ ){
                if (grade_list[j] < grade_list[i]){      // 점수 비교

                    int Itemp = grade_list[i];         // 점수 정렬
                    grade_list[i] = grade_list[j];
                    grade_list[j] = Itemp;

                    String Stemp = name_list[i];        // 이름 정렬
                    name_list[i] = name_list[j];
                    name_list[j] = Stemp;
                }
            }
        }
        for (int k =0; k < N ; k++ ){
            System.out.println(name_list[k]+grade_list[k]);
        }
    }    
}
