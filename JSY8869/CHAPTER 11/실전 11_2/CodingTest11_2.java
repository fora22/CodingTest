import java.util.*;

public class CodingTest11_2 {
    public static void main(String[] args){
        String str = TestCase();
        String[] NumberList = str.split("");
        int[] Number = new int[NumberList.length];
        for(int i = 0; i < NumberList.length; i++){
            Number[i] = Integer.parseInt(NumberList[i]);
        }

        for(int i = 0; i < Number.length-1; i++){
            if(Number[i] == 0 || Number[i] == 1 || Number[i+1] == 1 || Number[i+1] == 0){
                Number[i+1] += Number[i];
            }
            else{
                Number[i+1] *= Number[i];
            }
        }

        System.out.println(Number[Number.length-1]);
    }
    
    public static String TestCase(){
        Scanner sc = new Scanner(System.in);
        System.out.println("테스트 케이스 선택");
        System.out.println("0. 02984");
        System.out.println("1. 31058");
        System.out.println("2. 428150");
        int select_case = sc.nextInt();
        String[] test_case = {"02984", "31058", "428150"};
        return test_case[select_case];
    }
}
