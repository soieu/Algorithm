#include <iostream>
#include <vector>
using namespace std;

int dp[10002][4] = {
    0,
};
void dpf()
{
    dp[0][1] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 10000; i++)
    {
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        if (i >= 3)
            dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    dpf();
    while (T--)
    {
        int n;
        cin >> n;

        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }

    return 0;
}