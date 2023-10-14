#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int arr[500001] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        while (!v.empty() && arr[v.back()] < arr[i])
        {
            v.pop_back();
        }
        if (!v.empty())
        {
            cout << v.back() + 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
        v.push_back(i);
    }

    return 0;
}