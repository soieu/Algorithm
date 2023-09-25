#include <iostream>
#include <vector>
using namespace std;

int dp[1001][11] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
        dp[1][10] += dp[1][i];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = j; k < 10; k++)
            {
                dp[i][j] += dp[i - 1][k] % 10007;
            }
            dp[i][10] += dp[i][j] % 10007;
        }
    }
    cout << dp[n][10] % 10007;
    return 0;
}