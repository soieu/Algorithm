#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
        dp.push_back(temp); // 입력하면서 초기화
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[j] + arr[i], dp[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
    return 0;
}