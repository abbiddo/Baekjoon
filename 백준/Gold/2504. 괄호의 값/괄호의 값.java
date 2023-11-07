import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if (c == '('){
                stack.push(0);
            } else if (c == '['){
                stack.push(1);
            } else if (c == ')'){
                int semi = 0;
                while(!stack.isEmpty()){
                    int n = stack.pop();
                    if (n == 0){
                        if (semi == 0) semi = 1;
                        stack.push(semi * 2);
                        break;
                    } else if (n == 1){
                        System.out.println(0);
                        return;
                    } else {
                        semi += n;
                    }
                }
                if (stack.isEmpty()){
                    System.out.println(0);
                    return;
                }
            } else {
                int semi = 0;
                while(!stack.isEmpty()){
                    int n = stack.pop();
                    if (n == 1){
                        if (semi == 0) semi = 1;
                        stack.push(semi * 3);
                        break;
                    } else if (n == 0){
                        System.out.println(0);
                        return;
                    } else {
                        semi += n;
                    }
                }
                if (stack.isEmpty()){
                    System.out.println(0);
                    return;
                }
            }
        }

        int result = 0;
        while(!stack.isEmpty()){
            int n = stack.pop();
            if (n == 0 || n == 1){
                System.out.println(0);
                return;
            }
            result += n;
        }
        System.out.println(result);
    }
}