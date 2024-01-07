#include <iostream>
#include <vector>
using namespace std;

int arr[10] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    string num = to_string(a * b * c);

    for (int i = 0; i < num.length(); i++)
    {
        arr[num[i] - '0']++;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << "\n";
    }

    return 0;
}