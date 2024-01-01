#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, top = 0, bottom = 0, result = 0;

    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (top < temp)
            top = temp;
        v.push_back(temp);
    }

    while (bottom <= top)
    {
        long long int total = 0;
        int mid = (top + bottom) / 2;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > mid)
            {
                total += v[i] - mid;
            }
        }
        if (total < m)
        {
            top = mid - 1;
        }
        else
        {
            result = mid;
            bottom = mid + 1;
        }
    }
    cout << result;

    return 0;
}