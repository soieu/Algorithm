import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.EmptyStackException;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> stack = new Stack<>();
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int flag = 0;
            String input = br.readLine();
            for (int i = 0; i < input.length(); i++) {
                char c = input.charAt(i);
                if (c == '(') {
                    stack.push(i);
                } else if (c == ')') {
                    try {
                        stack.pop();
                    } catch (EmptyStackException e) {
                        System.out.println("NO");
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 1) {
                continue;
            }
            if (stack.isEmpty()) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            while(!stack.isEmpty()) {
                stack.pop();
            }
        }
        return;
    }

}
