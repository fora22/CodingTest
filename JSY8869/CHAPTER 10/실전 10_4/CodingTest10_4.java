import java.util.*;
import java.util.ArrayList;
class CodingTest10_4{
    public static ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
    public static int[] indegree = new int[100001];
    public static int N;
    public static int[] time = new int[501];

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = 4;
        int temp = 0;
        list.add(new ArrayList<Integer>());
        for(int i = 1; i <= N; i++){
            time[i] = sc.nextInt();
            list.add(new ArrayList<Integer>());
            minuswhile : while(true){
                temp = sc.nextInt();
                if(temp == -1){
                    break minuswhile;
                }
                indegree[i] += 1;
                list.get(temp).add(i);
            }
        }
        topologySort();
    }
    public static void topologySort() {
        int[] result = new int[501];
        for(int i = 1; i <= N; i++){
            result[i] = time[i];
        }
        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        while (!q.isEmpty()) {
            int now = q.poll();
            for (int i = 0; i < list.get(now).size(); i++) {
                result[list.get(now).get(i)] = Math.max(result[list.get(now).get(i)], result[now] + time[list.get(now).get(i)]);
                indegree[list.get(now).get(i)] -= 1;
                if (indegree[list.get(now).get(i)] == 0) {
                    q.offer(list.get(now).get(i));
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            System.out.println(result[i]);
        }
    }
}