

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n;
        int result = 0;
        int max = 0;
        double afterSum = 0;

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // 0. n 크기의 배열 만들기
        int[] arr = new int[n];

        // 1. 입력받기
        for (int i = 0 ; i < n; i++) {
            int temp = sc.nextInt();
            if (max < temp) {
                max = temp;
            }
            arr[i] = temp;
        }

        for(int i : arr) {
            afterSum += ((double)i/max) * 100;
        }

        System.out.println(afterSum / n);
    }
}
