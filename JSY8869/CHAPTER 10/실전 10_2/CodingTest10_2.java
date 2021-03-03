import java.util.*;
class CodingTest10_2 {
    public static int[] parent = new int[100000];
    public static int N, M;
    public static void main(String[] args){
        CodingTest10_2 temp = new CodingTest10_2();
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        int a, b, s;
        for(int i = 1; i < N+1; i++){
            parent[i] = i;
        }
        for(int i = 0; i < M; i ++){
            s = sc.nextInt();
            a = sc.nextInt();
            b = sc.nextInt();
            if(s == 0){
                temp.union_parent(a, b);
            }
            else if(s == 1){
                if(parent[a] == parent[b]){
                    System.out.println("YES");
                }
                else{
                    System.out.println("NO");
                }
            }

        }
    }
    public int find_parent(int x){
        if (parent[x] != x){
            return find_parent(parent[x]);    // 부모가 자기자신이 아닌 경우 재귀를 통해 부모의 부모를 탐색
        }
        return x;      // 자기 자신이 부모인 경우
    }

    public void union_parent(int a, int b){
        a = find_parent(a);
        b = find_parent(b);
        if (a < b){
            parent[b] = a;
        }else{
            parent[a] = b;
        }
    }
}