import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.util.Collections.*;

public class Main {
    public static void main(String[] args) throws IOException {

        int n;
        int m;
        int res = Integer.MIN_VALUE;
        int arr[];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += arr[i];
        }

        res = Math.max(res, sum);
        for (int i = m; i < n; i++){
            sum += arr[i];
            sum -= arr[i-m];
            res = Math.max(res, sum);
        }

        System.out.println(res);
    }
}