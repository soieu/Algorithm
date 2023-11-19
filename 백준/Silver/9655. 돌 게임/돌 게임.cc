#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int turn = 1;
    while (n != 0)
    {
        if (n >= 3)
        {
            n = n - 3;
        }
        else
        {
            n = n - 1;
        }
        turn = turn * -1;
    }

    if (turn == -1)
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }

    return 0;
}