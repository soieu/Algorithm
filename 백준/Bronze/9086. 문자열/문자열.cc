#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << a[0] << a[a.size() - 1] << "\n";
    }
    return 0;
}