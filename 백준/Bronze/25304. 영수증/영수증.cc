#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    int n;
    int a, b;
    int result = 0;
    cin >> x >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        result += a * b;
    }
    if (x == result)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}