import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int res;

    static Egg[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        arr = new Egg[n];

        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int strong = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            arr[i] = new Egg(weight, strong);
        }

        dfs(0);

        System.out.println(res);
    }

    public static void dfs(int current){
        if (current == n){
            int cnt = 0;
            for (int i = 0; i < n; i++){
                if (arr[i].strong <= 0){
                    cnt++;
                }
            }
            res = Math.max(res, cnt);

            return;
        }

        if (arr[current].strong <= 0) {
            dfs(current + 1);
            return;
        }

        int count = 0;

        for (int i = 0; i < n; i++){
            if (arr[i].strong <= 0) continue;
            if (current == i) continue;

            arr[current].strong -= arr[i].weight;
            arr[i].strong -= arr[current].weight;

            count++;
            dfs(current + 1);

            arr[current].strong += arr[i].weight;
            arr[i].strong += arr[current].weight;
        }

        if (count == 0) {
            dfs(current + 1);
        }
    }

    static class Egg{
        int weight;
        int strong;

        public Egg(int w, int s){
            this.weight = w;
            this.strong = s;
        }
    }
}