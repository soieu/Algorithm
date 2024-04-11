import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // 0. n 크기의 배열 만들기
        int[] arr = new int[n];

        // 1. 입력받기
        for (int i = 0; i < n; i++) {
            int temp = sc.nextInt();
            arr[i] = temp;
        }

        // 2. 정렬 후 출력
        Arrays.sort(arr);
        for (int i : arr) {
            System.out.println(i);
        }
    }
}
