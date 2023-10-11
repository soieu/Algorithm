#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long int n, r, result;
    cin >> n >> r;

    result = n + (r - 1) * 2 + 1;
    cout << result;
    return 0;
}