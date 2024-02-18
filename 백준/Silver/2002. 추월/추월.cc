#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> h;

    int n;
    int count = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string car;
        cin >> car;
        h.push_back(car);
    }

    int fix = 0;
    for (int i = 0; i < n; i++)
    {
        string car;

        cin >> car;

        if (car != h[fix])
        {
            count++;
            h.erase(remove(h.begin(), h.end(), car), h.end());
        }
        else
        {
            fix++;
        }
    }

    cout << count;

    return 0;
}