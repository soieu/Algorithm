import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    // 모듈러 값 정의
    private static final int MOD = 1_000_000_000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 입력 값
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        // DP 테이블 초기화
        int[][] dp = new int[N + 1][K + 1];

        // dp[1][i]는 i로 초기화
        for (int i = 0; i <= K; i++) {
            dp[1][i] = i;
        }

        // DP 계산
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }

        // 결과 출력
        System.out.println(dp[N][K]);
    }
}
