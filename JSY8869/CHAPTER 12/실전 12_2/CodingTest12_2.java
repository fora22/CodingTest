import java.util.*;

class CodingTest12_2{
    public static void main(String[] args){
        int intS = 0;
        char[] s = {'K','1','K','A','5','C','B','7'};
        Arrays.sort(s);
        String str = String.valueOf(s);
        String str_int;
        str_int = str.replaceAll("[^0-9]", "");
        str = str.replaceAll("[0-9]", "");
        for(int i = 0; i < str_int.length(); i++){
            intS += Integer.parseInt(String.valueOf(str_int.charAt(i)));
        }
        str += String.valueOf(intS);
        System.out.println(str);
    }
}