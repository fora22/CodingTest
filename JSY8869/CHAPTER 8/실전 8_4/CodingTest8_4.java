import java.math.BigInteger;
import java.util.*;
class CodingTest8_4{
    public static void main(String[] args){
        Random random = new Random();
        int N = random.nextInt(1000)+1;
        BigInteger temp = new BigInteger("796796");      // 796796으로 나누기 위한 BigInteger 변수
        BigInteger[] result = new BigInteger[N];
        result[0] = BigInteger.ONE;        // 0번째는 항상 1이므로 지정
        if(N > 1){
            result[1] = BigInteger.ONE.add(BigInteger.TWO); // N이 1보다 클 때 1번째 값을 지정(N의 값에 따른 범위 문제)
            for (int i = 2; i < N; i++){
                result[i] = result[i-1].add(result[i - 2].multiply(BigInteger.TWO));     // i번째는 i-1번째 + (i-2번째 * 2)
            }
        }
        System.out.println(result[N-1].mod(temp));   // 결과 = N-1번째의 796796으로 나눈 나머지
    }
}