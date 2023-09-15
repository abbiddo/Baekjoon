import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int m;
    static int l;
    static int res = 0;

    static int[] DR = {0, 1, 0, -1};
    static int[] DC = {1, 0, -1, 0};

    static char[][] arr;
    static boolean[][] vis;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());

        arr = new char[n][m];
        vis = new boolean[n][m];

        for (int i = 0; i < n; i++){
            arr[i] = br.readLine().toCharArray();
        }

        vis[n - 1][0] = true;

        dfs(n - 1, 0, 1);

        System.out.println(res);
    }

    public static void dfs(int r, int c, int cnt){

        if (r == 0 && c == m - 1) {
            if (cnt == l)
                res++;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nextR = r + DR[i];
            int nextC = c + DC[i];

            if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= m)
                continue;

            if (arr[nextR][nextC] == 'T' || vis[nextR][nextC])
                continue;

            vis[nextR][nextC] = true;

            dfs(nextR, nextC, cnt + 1);

            vis[nextR][nextC] = false;
        }
    }
}