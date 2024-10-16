import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int result = 0;

        for(int i = 0; i < N; i++) {
            pq.add(Integer.parseInt(br.readLine()));
        }
        while(pq.size() != 1) {
            int one = pq.poll();
            int two = pq.poll();
            pq.add(one+two);
            result += one+two;
        }

        System.out.println(result);

    }
}
