#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> v;

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
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    int l = 0, r = v.size() - 1;
    int r_l = 0, r_r = v.size() - 1;

    while (l < r)
    {
        if (abs(v[l] + v[r]) < abs(v[r_l] + v[r_r]))
        {
            r_l = l;
            r_r = r;
        }
        if (v[l] + v[r] > 0)
        {
            r--;
        }
        else
        {
            l++;
        }
    }

    cout << v[r_l] << " " << v[r_r] << endl;

    return 0;
}