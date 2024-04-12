import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        long[][] map = new long[n+1][n+1];

        for(int i = 1; i <= n; i++)
        {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= n; j++)
            {
                int temp = Integer.parseInt(st.nextToken());
                map[i][j] = temp + map[i-1][j] + map[i][j-1] - map[i-1][j-1];
            }
        }

        for(int i = 0; i < m; i++)
        {
            st = new StringTokenizer(br.readLine());
            int y1 = Integer.parseInt(st.nextToken());
            int x1 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());

            System.out.println(map[y2][x2] - map[y1-1][x2] - map[y2][x1-1] + map[y1-1][x1-1]);

        }
    }
}
