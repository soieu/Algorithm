#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1500100] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int section_max = 0;
    cin >> n;
    // 초기화
    for (int i = 1; i <= n; i++)
    {
        int time, pay;
        cin >> time >> pay;
        // cout << "\n"
        //      << i + time - 1 << " 일째 : "
        //      << dp[i - 1] << ", " << pay << ", " << dp[i] << endl;

        dp[i + time - 1] = max(section_max + pay, dp[i + time - 1]);
        if (dp[i] > section_max)
            section_max = dp[i];
        // cout << i + time - 1 << "일째는 결국" << dp[i + time - 1] << "가 됐습니다";
    }

    int max = *max_element(dp, dp + n + 1);
    cout << max;

    return 0;
}