import java.io.*;
import java.util.*;

public class Main {
    static int N;                  // 장소의 개수
    static int[] place;            // 각 장소의 꿀 양
    static long[] rightPlace;      // 왼쪽 -> 오른쪽으로 누적합
    static long[] leftPlace;       // 오른쪽 -> 왼쪽으로 누적합
    static long total;             // 전체 꿀의 양 합계
    static long maxHoney;          // 최대 꿀 양

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        place = new int[N];
        rightPlace = new long[N];
        leftPlace = new long[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            place[i] = Integer.parseInt(st.nextToken());
        }

        // 누적합 계산 (왼쪽 -> 오른쪽)
        rightPlace[0] = place[0];
        for (int i = 1; i < N; i++) {
            rightPlace[i] = rightPlace[i - 1] + place[i];
        }

        // 누적합 계산 (오른쪽 -> 왼쪽)
        leftPlace[N - 1] = place[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            leftPlace[i] = leftPlace[i + 1] + place[i];
        }

        // 전체 꿀 양
        total = rightPlace[N - 1];

        // 경우 1: 벌통이 오른쪽 끝에 있고, 벌 1은 왼쪽 끝에 있는 경우
        for (int i = 1; i <= N - 2; i++) {
            long bee1 = total - place[0] - place[i];
            long bee2 = total - rightPlace[i];
            maxHoney = Math.max(maxHoney, bee1 + bee2);
        }

        // 경우 2: 벌통이 왼쪽 끝에 있고, 벌 2는 오른쪽 끝에 있는 경우
        for (int i = N - 2; i >= 1; i--) {
            long bee1 = total - place[N - 1] - place[i];
            long bee2 = total - leftPlace[i];
            maxHoney = Math.max(maxHoney, bee1 + bee2);
        }

        // 경우 3: 벌통이 중간에 있는 경우 (벌 1은 왼쪽 끝, 벌 2는 오른쪽 끝)
        for (int i = 1; i <= N - 2; i++) {
            long bee1 = rightPlace[i] - place[0];
            long bee2 = leftPlace[i] - place[N - 1];
            maxHoney = Math.max(maxHoney, bee1 + bee2);
        }

        // 최대 꿀 양 출력
        System.out.println(maxHoney);
    }
}
