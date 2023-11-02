import java.io.*;
import java.util.*;

public class Main {
    static int a;
    static int b;
    static int c;
    static int sum;
    static boolean[][] visit;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n1 = Integer.parseInt(st.nextToken());
        int n2 = Integer.parseInt(st.nextToken());
        int n3 = Integer.parseInt(st.nextToken());

        sum = n1 + n2 + n3;
        if (sum % 3 != 0){
            System.out.println(0);
            return;
        }

        a = Math.min(n1, Math.min(n2, n3));
        c = Math.max(n1, Math.max(n2, n3));
        b = sum - a - c;

        visit = new boolean[1501][1501];

        System.out.println(bfs());
    }

    public static int bfs(){
        Queue<Stone> q = new LinkedList<>();
        q.add(new Stone(a, b, c));
        while (!q.isEmpty()){
            Stone s = q.poll();

            if (s.A == s.B && s.B == s.C){
                return 1;
            }

            if (s.A != s.B) {
                int n1 = s.A * 2;
                int n2 = s.B - s.A;
                int n3 = s.C;

                int aa = Math.min(n1, Math.min(n2, n3));
                int cc = Math.max(n1, Math.max(n2, n3));
                int bb = sum - aa - cc;

                if (!visit[aa][cc]){
                    q.add(new Stone(aa, bb, cc));
                    visit[aa][cc] = true;
                }
            }

            if (s.A != s.C) {
                int n1 = s.A * 2;
                int n2 = s.C - s.A;
                int n3 = s.B;

                int aa = Math.min(n1, Math.min(n2, n3));
                int cc = Math.max(n1, Math.max(n2, n3));
                int bb = sum - aa - cc;

                if (!visit[aa][cc]){
                    q.add(new Stone(aa, bb, cc));
                    visit[aa][cc] = true;
                }
            }

            if (s.B != s.C) {
                int n1 = s.B * 2;
                int n2 = s.C - s.B;
                int n3 = s.A;

                int aa = Math.min(n1, Math.min(n2, n3));
                int cc = Math.max(n1, Math.max(n2, n3));
                int bb = sum - aa - cc;

                if (!visit[aa][cc]){
                    q.add(new Stone(aa, bb, cc));
                    visit[aa][cc] = true;
                }
            }
        }
        return 0;
    }

    static class Stone {
        public int A, B, C;

        public Stone(int A, int B, int C){
            this.A = A;
            this.B = B;
            this.C = C;
        }
    }
}