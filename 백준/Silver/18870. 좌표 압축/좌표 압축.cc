#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input;
vector<int> sorted;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        input.push_back(num);
        sorted.push_back(num);
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for (int i = 0; i < n; i++)
    {
        cout << lower_bound(sorted.begin(), sorted.end(), input[i]) - sorted.begin() << " ";
    }

    return 0;
}