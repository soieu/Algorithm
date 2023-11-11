#include <iostream>
#include <vector>
using namespace std;
int n = 0;

void hanoi(int n, int start, int via, int to)
{
    if (n == 1)
    {
        cout << start << " " << to << "\n";
        return;
    }
    else
    {
        hanoi(n - 1, start, to, via);
        hanoi(1, start, via, to);
        hanoi(n - 1, via, start, to);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int count = (1 << n) - 1;
    cout << count << "\n";

    hanoi(n, 1, 2, 3);

    return 0;
}