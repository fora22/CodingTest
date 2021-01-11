import java.util.*;

public class CodingTest7_3 {
    public static void main(String[] args){
        Random random = new Random();
        int N = random.nextInt(1000000) + 1;
        int M = random.nextInt(2000000000) + 1;
        int[] DDUCK = new int[N];
        for(int i = 0; i < N; i++){
            DDUCK[i] = random.nextInt(1000000001);
        }

        int result = 0;
        Arrays.sort(DDUCK);
        double middle_temp = (DDUCK[0] + DDUCK[N-1])/2;
        int middle = (int)(middle_temp);
        int pre_middle = 0;
        int start = 0;
        int end = DDUCK[N-1];
        main_while : while(true){
            result = 0;
            find_result : for(int j = N-1; j >= 0; j--){         // 현재 middle값으로 얻을 수 있는 떡의 양 계산
                if(DDUCK[j] - middle > 0){
                    result = result + (DDUCK[j] - middle);
                }
                else{
                    break find_result;
                }
            }
            pre_middle = middle;
            if(result > M){                   //  result와 M을 비교하여 이진탐색 범위 설정
                middle_temp = (middle + end)/2;
                middle = (int)(middle_temp);
                start = pre_middle;
            }
            else{
                middle_temp = (middle + start)/2;
                middle = (int)(middle_temp);
                end = pre_middle;
            }
            if(start >= end){      // 이진 탐색 종료
                break main_while;
            }
            else if(end - start == 1){    // 무한 반복 방지
                break main_while;
            }
        }
        System.out.println((int)(middle_temp));
    }   
}
