import java.util.*;
class CodingTest6_2{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int arr[] = new int[N];
        for(int i = 0; i < N; i++){
            arr[i] = scanner.nextInt();
        }
        Arrays.sort(arr);
        
        for (int j : arr) {
            System.out.printf("%d ", j);
        }
    }
}