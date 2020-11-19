import java.util.*;
class CodingTest_Practice_4_1{
    public static void main(String[] args){
        Random random = new Random();
        String RD_row = String.valueOf((char) ((int) (random.nextInt(8)) + 97));  // a ~ h 랜덤 생성
        int RD_column = random.nextInt(8)+1; // 1~8 랜덤 생성
        String input = RD_row + RD_column; // 입력 값
        
        int row = (Character.getNumericValue(input.charAt(0))-9); // input에서 첫번째 값을 char 값으로 바꾼 후 int 값으로 변경하여 저장
        int column = (Character.getNumericValue(input.charAt(1))); // input에서 두번째 값을 char 값으로 바꾼 후 int 값으로 변경하여 저장
        int count = 0;

        if (column + 1 > 0){
            count = row_Cal_1(row, count);
        }
        if (column + 2 > 0){
            count = row_Cal_2(row, count);
        }
        if (column - 1 > 0){
            count = row_Cal_1(row, count);
        }
        if (column - 2 > 0){
            count = row_Cal_2(row, count);
        }
        System.out.println(count);
    }
    public static int row_Cal_1(int row, int count){
        if (row + 2 > 0)
            count += 1;
        if (row - 2 > 0)
            count += 1;
        return count;
    }
    public static int row_Cal_2(int row, int count){
        if (row + 1 > 0)
            count += 1;
        if (row - 1 > 0)
            count += 1;
        return count;
    }
}