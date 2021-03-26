import java.util.*;
public class CodingTest11_1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int result = 0;
        int count = 0;
        Integer[] Fear = {2, 3, 1, 2, 2, 1, 3, 4};
        Arrays.sort(Fear,Collections.reverseOrder());
        int stat = Fear[0];
        int location = 0;
        main_while : while(true){
            count = stat;
            result += 1;
            while(count > 0){
                count -= 1;
                location += 1;
            }
            try{
                stat = Fear[location];
            }catch(Exception e){
                break main_while;
            }
        }
        System.out.println(result);
    }
}
