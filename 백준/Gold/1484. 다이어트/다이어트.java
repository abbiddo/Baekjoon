import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n;
        n = Integer.parseInt(br.readLine());

        int left = 1;
        int right = 2;
        int cnt = 0;

        while (left <= (n+1)/2 && right <= (n+1)/2 && left <= right){
            int sum = (right * right) - (left * left);
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