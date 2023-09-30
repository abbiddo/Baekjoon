import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static String s;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        for (int i =0; i < n ;i ++) {
            s = br.readLine();

            if (solve(0, s.length() - 1)){
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    public static boolean solve(int left, int right) {
        if (left >= right){
            return true;
        }

        int mid = (left + right) / 2;
        for (int i = left; i < mid; i++){
            if (s.charAt(i) == s.charAt(right - i)){
                return false;
            }
        }
        return solve(left, mid - 1) && solve(mid + 1, right);
    }
}