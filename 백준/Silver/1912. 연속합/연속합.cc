#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
        dp[i] = -0x7fffffff;
    }
    dp[0] = v[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + v[i], v[i]);
    }

    cout << *max_element(dp, dp + n);

    return 0;
}