import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        
        int[] prefixSum = new int[n];

        for(int i = 0; i < n; i++){
            int temp = sc.nextInt();
            prefixSum[i] = temp + (i == 0 ? 0 : prefixSum[i-1]);

        }

        for(int i = 0; i < m; i++) {
            int t1 = sc.nextInt();
            int t2 = sc.nextInt();
            System.out.println(prefixSum[t2-1] - (t1 == 1 ? 0 : prefixSum[t1-2]));
        }


    }
}
