import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        Queue<Integer> q = new LinkedList<>();
        int[] b = new int[10000000];
        float target = 9*M/10.0f;

        StringTokenizer st2 = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int f = Integer.parseInt(st2.nextToken());
            q.add(f);
            b[f]++;
            if(b[f] >= target){
                System.out.println("YES");
                return;
            }
            if(q.size() >= M){
                int x = q.poll();
                b[x]--;
            }
        }
        System.out.println("NO");
    }
}
