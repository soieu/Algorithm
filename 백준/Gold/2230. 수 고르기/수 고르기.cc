#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int result = 0x7fffffff;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    int first = 0;
    int last = 0;
    while (first < n && last < n)
    {
        if (v[last] - v[first] >= m)
        {
            result = min(result, v[last] - v[first]);
            first++;
        }
        else
        {
            last++;
        }
    }
    cout << result;

    return 0;
}