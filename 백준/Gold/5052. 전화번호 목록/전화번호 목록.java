import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++){
            boolean check = false;
            int n = Integer.parseInt(br.readLine());
            String[] arr = new String[n];
            for (int j = 0; j < n; j++){
                arr[j] = br.readLine();
            }

            Arrays.sort(arr);

            for (int j = 1; j < n; j++){
                if (arr[j].startsWith(arr[j - 1])){
                    System.out.println("NO");
                    check = true;
                    break;
                }
            }

            if (!check) System.out.println("YES");
        }

    }
}