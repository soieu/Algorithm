class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int MOD = 1000000007;
        int[][] dp = new int[n][m];

        // 웅덩이 위치 설정 (1-based → 0-based)
        for (int[] puddle : puddles) {
            dp[puddle[1] - 1][puddle[0] - 1] = -1;
        }

        // 시작점 설정
        dp[0][0] = 1;

        // DP 계산
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 웅덩이는 0으로 설정
                if (dp[i][j] == -1) {
                    dp[i][j] = 0;
                    continue;
                }
                
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }

        return dp[n - 1][m - 1];
    }
}
