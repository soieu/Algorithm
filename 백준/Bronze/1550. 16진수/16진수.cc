#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a;
    cin >> a;
    int num = 0;

    for (int i = 0; i < a.size(); i++)
    {
        num *= 16;
        num += (a[i] >= '0' && a[i] <= '9') ? a[i] - '0' : a[i] - 'A' + 10;
    }
    cout << num;

    return 0;
}