#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void hanoi(int num, int from, int by, int to)
{
    if (num == 1)
        cout << from << " " << to << "\n";
    else
    {
        hanoi(num - 1, from, to, by);
        cout << from << " " << to << "\n";
        hanoi(num - 1, by, from, to);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    string a = to_string(pow(2, N));
    int index = a.find(".");
    a = a.substr(0, index);
    a[a.size() - 1] -= 1;

    cout << a << "\n";

    if (N <= 20)
        hanoi(N, 1, 2, 3);

    return 0;
}