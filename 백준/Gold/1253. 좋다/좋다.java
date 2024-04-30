

import java.util.*;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        int count = 0;

        int[] arr = new int[num];

        for (int i = 0; i < num; i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        for (int i = 0; i < num; i++) {
            int start = 0;
            int end = num - 1;
            while (start < end) {
                if (start == i ) {
                    start++;
                }
                else if(end == i) {
                    end--;
                }
                else if (arr[start] + arr[end] == arr[i]) {
                    count++;
                    break;
                } else if (arr[start] + arr[end] < arr[i]) {
                    start++;
                } else if (arr[start] + arr[end] > arr[i]){
                    end--;
                }
            }
        }
        System.out.println(count);
    }
}