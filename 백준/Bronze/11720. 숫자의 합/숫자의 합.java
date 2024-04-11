

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n;
        int result = 0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // 0. n 크기의 배열 만들기
        int[] arr = new int[n];

        // 1. 입력받기
        String temp = sc.next();

        for (char i : temp.toCharArray()) {
            result += i - '0';
        }
        System.out.println(result);
    }
}
