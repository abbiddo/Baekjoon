import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        long res = 0;
        long sum = 0;
        long[] mod = new long[m];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++){
            sum += Long.parseLong(st.nextToken());
            mod[(int)(sum % m)]++;
        }

        for (int i = 0; i < m; i++){
            res += (mod[i] - 1) * mod[i] / 2;
        }
        System.out.println(res + mod[0]);
    }
}