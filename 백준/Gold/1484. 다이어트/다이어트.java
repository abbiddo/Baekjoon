import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n;
    static int cnt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        long left = 1;
        long right = 2;

        while (left <= n && right <= n && left <= right){
            long sum = (right * right) - (left * left);
            if (sum == n){
                System.out.println(right);
                cnt++;
                left++;
            } else if (sum < n){
                right++;
            } else {
                left++;
            }
        }

        if (cnt == 0){
            System.out.println(-1);
        }
    }
}