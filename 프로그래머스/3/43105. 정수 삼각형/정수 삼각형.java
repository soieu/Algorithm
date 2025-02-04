import java.util.Arrays;

class Solution {
    public int solution(int[][] triangle) {
        int tLen = triangle.length;
        int[][] dp = new int[tLen][tLen]; // 메모리 최적화 -> triangle처럼 삼각형 모양으로 만들기
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < tLen; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }

        return Arrays.stream(dp[tLen - 1]).max().getAsInt();
    }
}