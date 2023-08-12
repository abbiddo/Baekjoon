import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        String p = br.readLine();

        int ssize = s.length();
        int res = 0;

        while (p.length() != 0){
            for (int i = Math.min(ssize, p.length()); i > 0; i--){
                String substr = p.substring(0, i);
                int index = s.indexOf(substr);
                if (index != -1) {
                    p = p.substring(i);
                    break;
                }
            }
            res++;
        }

        System.out.println(res);
    }
}