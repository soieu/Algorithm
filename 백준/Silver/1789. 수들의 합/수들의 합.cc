#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    long long int s;
    cin >> s;

    long long int sum = 0, num = 1;

    while (1)
    {
        if (sum > s)
        {
            num -= 2;
            break;
        }
        sum = sum + num++;
    }

    cout << num;
    return 0;
}