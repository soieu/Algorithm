
import java.util.Scanner;
public class Main {
    public static void backTracking(int len, int[] visited, int idx, int[] arr, int n) {

        if(idx == len) {
            for(int i = 0; i < arr.length; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.print("\n");
            return ;
        }

        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0) {
                arr[idx] = i;
                visited[i] = 1;
                backTracking(len, visited, idx + 1, arr, n);
                visited[i] = 0;
                arr[idx] = 0;
            }

        }

    }
    public static void main(String[] args) {
        int n, m;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        int[] arr = new int[m];
        int[] visited = new int[n+1];
        backTracking(m,visited,0,arr,n);

    }
}