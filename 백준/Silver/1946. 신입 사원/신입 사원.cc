#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        vector<pair<int, int>> v;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());

        int count = 1;
        int tjfb = v[0].first;
        int auswjq = v[0].second;
        for (int i = 1; i < n; i++)
        {
            if (v[i].second < auswjq)
            {
                count++;
                auswjq = v[i].second;
            }
        }
        cout << count << "\n";
    }

    return 0;
}