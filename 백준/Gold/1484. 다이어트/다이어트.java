import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static long n;
    static boolean flag = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        long bound = (n + 1) / 2;
        
        for (long i = 1; i <= bound; i++){
            long tmp = i * i - n;
            if (tmp <= 0){
                continue;
            }

            double tmpSqrt = Math.sqrt(tmp);
            long tmpLong = (long)tmpSqrt;

            if (tmpSqrt == tmpLong){
                flag = true;
                System.out.println(i);
            }
        }

        if (!flag) System.out.println(-1);
    }
}