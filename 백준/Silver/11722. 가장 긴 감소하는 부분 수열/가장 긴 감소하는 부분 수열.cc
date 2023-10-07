#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[1001] = {
    0,
};
int arr[1001] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(dp, dp + 1001, 1);

    int n = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[i] < arr[j])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    int max_len = *max_element(begin(dp), end(dp));

    cout << max_len;
    return 0;
}