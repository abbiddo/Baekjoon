import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int one;
    static int minus;
    static long res;
    static long[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        arr = new long[n];

        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            arr[i] = Long.parseLong(st.nextToken());

            if (arr[i] <= 0){
                minus++;
            }else if (arr[i] == 1){
                one++;
            }
        }

        Arrays.sort(arr);

        for (int i = 0; i < minus; i += 2){
            if (i + 1 < minus){
                res += arr[i] * arr[i + 1];
            }else {
                res += arr[i];
            }
        }

        for (int i = n - 1; i >= minus + one; i-= 2){
            if (i - 1 >= minus + one){
                res += arr[i] * arr[i - 1];
            }
            else {
                res += arr[i];
            }
        }

        System.out.println(res + one);
    }
}