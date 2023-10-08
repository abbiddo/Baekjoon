import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int t;
    static int n;
    static int m;
    static long[] A;
    static long[] B;
    static List<Long> sumA;
    static List<Long> sumB;



    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        t = Integer.parseInt(br.readLine());

        n = Integer.parseInt(br.readLine());
        A = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++){
            A[i] = Long.parseLong(st.nextToken());
        }

        m = Integer.parseInt(br.readLine());
        B = new long[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++){
            B[i] = Long.parseLong(st.nextToken());
        }

        sumA = new ArrayList<>();
        for (int i = 0; i < n; i++){
            long tmp = 0;
            for (int j = i; j < n; j++){
                tmp += A[j];
                sumA.add(tmp);
            }
        }

        sumB = new ArrayList<>();
        for (int i = 0; i < m; i++){
            long tmp = 0;
            for (int j = i; j < m; j++){
                tmp += B[j];
                sumB.add(tmp);
            }
        }

        Collections.sort(sumA);
        Collections.sort(sumB);

        long res = 0;
        int left = 0;
        int right = sumB.size() - 1;
        while(left < sumA.size() && right >= 0){
            long sum = sumA.get(left) + sumB.get(right);
            if (sum == t){
                long a = sumA.get(left);
                long b = sumB.get(right);
                long cntA = 0;
                long cntB = 0;

                while(left < sumA.size() && sumA.get(left) == a){
                    cntA++;
                    left++;
                }

                while(right >= 0 && sumB.get(right) == b){
                    cntB++;
                    right--;
                }

                res += (cntA * cntB);
            }
            else if (sum < t){
                left++;
            }
            else if (sum > t){
                right--;
            }
        }

        System.out.println(res);
    }
}