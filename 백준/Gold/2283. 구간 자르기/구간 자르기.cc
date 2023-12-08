#include <iostream>
#include <vector>
using namespace std;

long long int lines[1000002] = {
    0,
};

long long int prefix[1000002] = {
    0,
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int temp_a, temp_b;
        cin >> temp_a >> temp_b;
        lines[temp_a]++;
        lines[temp_b]--;
    }

    // 각 위치마다의 걸리는 선의 개수
    for (int i = 0; i < 1000001; i++)
    {
        prefix[i + 1] = prefix[i] + lines[i];
    }

    int a = 1, b = 1;
    long long int sum = prefix[1] - prefix[0];
    while (true)
    {
        if (sum == k)
        {
            cout << a - 1 << " " << b;
            return 0;
        }
        else if (sum < k)
        {
            b++;
            if (b == 1000002)
            {
                break;
            }
            sum += prefix[b];
        }
        else if (sum > k)
        {
            sum -= prefix[a];
            a++;
            if (a == 1000002)
            {
                break;
            }
        }
    }
    cout << "0 0";

    return 0;
}