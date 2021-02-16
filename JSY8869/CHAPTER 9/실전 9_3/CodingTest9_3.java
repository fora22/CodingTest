import java.util.*;
class Node implements Comparable<Node> {

    private int index;
    private int distance;

    public Node(int index, int distance) {
        this.index = index;
        this.distance = distance;
    }

    public int getIndex() {
        return this.index;
    }

    public int getDistance() {
        return this.distance;
    }

    @Override
    public int compareTo(Node other) {
        if (this.distance < other.distance) {
            return -1;
        }
        return 1;
    }
}

public class CodingTest9_3 {

    public static int INF = 1000000000;
    public static int n, m, start;
    public static ArrayList<ArrayList<Node>> graph = new ArrayList<ArrayList<Node>>();
    public static int[] d = new int[100001];

    public static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        d[start] = 0;
        while(!pq.isEmpty()) {
            Node node = pq.poll();
            int dist = node.getDistance();
            int now = node.getIndex();

            if (d[now] < dist) continue;

            for (int i = 0; i < graph.get(now).size(); i++) {
                int cost = d[now] + graph.get(now).get(i).getDistance();

                if (cost < d[graph.get(now).get(i).getIndex()]) {
                    d[graph.get(now).get(i).getIndex()] = cost;
                    pq.offer(new Node(graph.get(now).get(i).getIndex(), cost));
                }
            }
        }
    }

    // 여기까지 다익스트라 알고리즘


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] test_a = {{1,1},{1,1,2,3},{1,3,4,5}};
        int[][] test_b = {{2,3},{2,3,4,4},{2,2,5,2}};
        int[][] test_c = {{4,2},{2,3,4,1},{1,3,2,4}};
        int[] test_n = {3,4,5};
        int[] test_m = {2,4,4};
        int[] test_start = {1,1,5};
        System.out.println("test case 1 or 2 or 3");
        int test_case = sc.nextInt() -1;
        n = test_n[test_case];
        m = test_m[test_case];
        start = test_start[test_case];
        int[] a = test_a[test_case];
        int[] b = test_b[test_case];
        int[] c = test_c[test_case];
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<Node>());
        }

        for (int i = 0; i < m; i++) {
            graph.get(a[i]).add(new Node(b[i], c[i]));
        }

        Arrays.fill(d, INF);
        
        dijkstra(start);

        int result = -1;
        for (int i = 1; i <= n; i++) {
            if (d[i] == INF) {
                d[i] = -1;
            }
            else{
                result += 1;
            }
        }
        Arrays.sort(d);
        System.out.print(result + " " + d[n-1]);
    }
}