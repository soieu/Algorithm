#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int reverse(int a)
{
    int x = 0;
    while (a > 0)
    {
        x *= 10;
        x += a % 10;
        a = a / 10;
    }

    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    a = reverse(a);
    b = reverse(b);

    cout << max(a, b);

    return 0;
}