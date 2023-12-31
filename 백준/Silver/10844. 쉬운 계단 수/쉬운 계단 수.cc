#include <iostream>
#include <vector>
#define mod 1000000000
using namespace std;

// n = 5
// 11111
// 11112
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    // 각 자리수마다 끝의 자리별로 경우의 수 저장
    int dp[101][10] = {
        0,
    };

    // 1의 자리의 경우 우선 한개씩 다 초기화
    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                dp[i][0] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][9] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            dp[i][j] %= mod;
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        result = (result + dp[n][i]) % mod;
    }
    cout << result << "\n";

    return 0;
}