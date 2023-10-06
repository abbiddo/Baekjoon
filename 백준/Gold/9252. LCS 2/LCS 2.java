import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int[][] dp;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s1;
        String s2;

        s1 = br.readLine();
        s2 = br.readLine();

        int size1 = s1.length();
        int size2 = s2.length();
        dp = new int[size1 + 1][size2 + 1];

        for (int i = 1; i <= size1; i++){
            char one = s1.charAt(i - 1);
            for (int j = 1; j <= size2; j++){
                if (s2.charAt(j - 1) == one) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                }

            }
        }

        char[] res = new char[dp[size1][size2]];
        int idx = dp[size1][size2] - 1;
        int max = dp[size1][size2];

        int r = size1;
        int c = size2;
        while(max > 0){
            if (dp[r][c - 1] == max){
                c--;
            } else if (dp[r - 1][c] == max){
                r--;
            } else {
                res[idx] = s1.charAt(r - 1);
                idx--;
                max--;
                r--;
                c--;
            }
        }

        System.out.println(dp[size1][size2]);
        for (char cc : res){
            System.out.print(cc);
        }
    }

}