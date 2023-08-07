import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.util.Collections.*;

public class Main {

    static int n;
    static int m;
    static int k;
    static boolean[][] arr;

    static int[] dr = {0, -1, 0, 1};
    static int[] dc = {1, 0, -1, 0};


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        arr = new boolean[n][m];

        for (int i = 0 ; i < k; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            for (int rr = b; rr < d; rr++){
                for (int cc = a; cc < c; cc++){
                    arr[rr][cc] = true;
                }
            }
        }

        ArrayList<Integer> res = new ArrayList<Integer>();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (arr[i][j] == false){
                    res.add(bfs(i, j));
                }
            }
        }

        sort(res);
        System.out.println(res.size());
        for (int result : res){
            System.out.print(result + " ");
        }

    }

    static int bfs(int r, int c){
        int cnt = 1;

        Queue<Pos> q = new LinkedList<>();
        q.add(new Pos(r, c));
        arr[r][c] = true;

        while(!q.isEmpty()){
            Pos cur = q.poll();

            for (int i = 0; i < 4; i++){
                int nextR = cur.row + dr[i];
                int nextC = cur.col + dc[i];

                if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= m) continue;
                if (arr[nextR][nextC] == true) continue;

                q.add(new Pos(nextR, nextC));
                arr[nextR][nextC] = true;
                cnt++;
            }
        }
        return cnt;
    }

    static class Pos{
        int row;
        int col;

        public Pos(int row, int col){
            this.row = row;
            this.col = col;
        }
    }
}