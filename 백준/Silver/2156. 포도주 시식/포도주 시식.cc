#include <iostream>
#include <vector>
using namespace std;

int dp[10001] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
        if (i == 0)
        {
            dp[i] = temp;
        }
        else if (i == 1)
        {
            dp[i] = temp + v[0];
        }
        else
        {
            dp[i] = max(dp[i - 3] + v[i - 1] + v[i], max(dp[i - 2] + v[i], dp[i - 1]));
        }
    }

    cout << dp[n - 1];

    return 0;
}