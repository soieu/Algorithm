#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int answer = 0;
    cin >> n >> m;
    int f = 0, l = 1;
    vector<int> v;
    int sum[10001] = {
        0,
    };
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sum[i + 1] = sum[i] + temp;
    }
    int temp;
    while (f != n)
    {
        temp = sum[l] - sum[f];
        if (temp == m)
        {
            answer++;
            f++;
        }
        else if (temp < m)
        {
            if (l == n)
                break;
            l++;
        }
        else
            f++;
    }
    cout << answer << "\n";

    return 0;
}