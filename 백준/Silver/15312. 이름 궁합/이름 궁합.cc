#include <iostream>
#include <vector>
using namespace std;

int AP[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int dp[2000];
int Arr[2001] = {
    0,
};
int bArr[2001] = {
    0,
};

void wornl(int size)
{
    if (size == 2)
        return;
    for (int i = 0; i < size - 1; i++)
    {
        Arr[i] = (Arr[i] + Arr[i + 1]) % 10;
    }
    wornl(size - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a;
    cin >> b;
    for (int i = 0; i < a.length(); i++)
    {
        Arr[i * 2] = AP[a[i] - 'A'];
        Arr[i * 2 + 1] = AP[b[i] - 'A'];
    }

    wornl(a.length() * 2);

    cout << Arr[0] << Arr[1];

    return 0;
}