#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;

    if (c <= b)
    {
        cout << -1;
        return 0;
    }
    else
    {
        int idx = (a / (c - b)) + 1;
        cout << idx;
    }

    return 0;
}