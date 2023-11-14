#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int maxx = 0;
int children[202] = {
    0,
};
int dp[202] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> children[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (children[j] < children[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        maxx = max(maxx, dp[i]);
    }
    cout << n - maxx;
    return 0;
}