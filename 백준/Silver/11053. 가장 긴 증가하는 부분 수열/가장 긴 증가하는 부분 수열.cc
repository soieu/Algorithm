#include <iostream>
#include <algorithm>
using namespace std;
int num[1001];
int dp[1001] = {
    0,
};

int max_len = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (num[j] < num[i] && dp[j] >= dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        max_len = max(max_len, dp[i]);
    }
    cout << max_len;
    return 0;
}