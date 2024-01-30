import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt();
            if (!s.isEmpty() && s.peek() < k) k = s.peek();
            s.push(k);
        }

        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            while (!s.isEmpty() && s.peek() < a) s.pop();
            if (!s.isEmpty()) s.pop();
            else {
                System.out.print(0);
                return;
            }
        }
        System.out.print(s.size() + 1);
    }
}
