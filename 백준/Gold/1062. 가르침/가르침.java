import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int m;
    static int res;
    static String[] arr;
    static boolean[] alpha;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        if (m < 5){
            System.out.println(0);
            return;
        }

        alpha = new boolean[26];

        alpha[0] = true;
        alpha[2] = true;
        alpha[8] = true;
        alpha[13] = true;
        alpha[19] = true;

        arr = new String[n];

        for (int i = 0; i < n; i++){
            arr[i] = br.readLine();
            arr[i] = arr[i].substring(4, arr[i].length() - 4);
        }

        study(1, 5);

        System.out.println(res);
    }

    public static void study(int cur, int cnt){
        if (cnt == m) {
            res = Math.max(res, check());
            return;
        }

        for(int i = cur; i < 26; i++){
            if (!alpha[i]){
                alpha[i] = true;
                study(i + 1, cnt + 1);
                alpha[i] = false;
            }
        }
    }

    public static int check(){
        int cnt = 0;
        for (String s : arr){
            int tmp = 0;
            for (int i = 0; i < s.length(); i++){
                if (!alpha[s.charAt(i) - 'a']){
                    break;
                }
                tmp++;
            }
            if (tmp == s.length()){
                cnt++;
            }
        }

        return cnt;
    }
}