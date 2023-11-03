#include <iostream>
#include <vector>
using namespace std;

int arr[100010] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 투포인터 이용
    int l = 0, r = 0;
    int resultI = 0x7fffffff, resultR = 0x7fffffff;
    int sum = arr[0];

    while (true)
    {
        if (l > r || r > n || l > n)
        {
            break;
        }

        if (sum >= s)
        {
            if (r - l < resultR - resultI || resultI == 0x7fffffff)
            {
                resultI = l;
                resultR = r;
            }
            // 현재 l값 제외
            sum -= arr[l++];
        }
        if (sum < s)
        {
            // 이후 r값 추가
            sum += arr[++r];
        }
    }

    if (resultI == 0x7fffffff)
    {
        cout << 0;
    }
    else
    {
        cout << resultR - resultI + 1;
    }

    return 0;
}