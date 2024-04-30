

import java.util.*;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int start = 1;
        int end = 1;
        int count = 0;
        int curSum = 1;

        while(start <= end && end <= n) {
            if(curSum < n) {
                curSum += ++end;
            }
            else if( curSum > n) {
                curSum -= start++;
            }
            else if(curSum == n) {
                count++;
                curSum += ++end;

            }
        }

        System.out.println(count);


    }
}