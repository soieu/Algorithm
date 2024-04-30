

import java.util.*;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean[] visited = new boolean[n];
        int count = 0;

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                if (visited[start]) {
                    start++;
                }
                else if (visited[end]) {
                    end--;
                }
                else if (arr[start] + arr[end] == m) {
                    count++;
                    visited[start] = true;
                    visited[end] = true;
                    break;
                } else if (arr[start] + arr[end] < m) {
                    start++;
                } else if (arr[start] + arr[end] > m){
                    end--;
                }
            }
        }
        System.out.println(count);
    }
}