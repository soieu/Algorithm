#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int result = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int s = 0, e = n - 1;
        while (s < e)
        {
            if (arr[s] + arr[e] == arr[i])
            {
                if (s != i && e != i)
                {
                    result++;
                    break;
                }
                else if (s == i)
                    s++;
                else if (e == i)
                    e--;
            }
            else if (arr[s] + arr[e] > arr[i])
            {
                e = e - 1;
            }
            else if (arr[s] + arr[e] < arr[i])
            {
                s = s + 1;
            }
        }
    }
    cout << result;

    return 0;
}