#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, c;
    vector<int> l;
    int bottom = 1;
    int top = 0;

    cin >> s >> c;
    long long sum = 0;
    for (int i = 0; i < s; i++)
    {
        int temp;
        cin >> temp;
        l.push_back(temp);
        top = max(top, temp);
        sum += temp;
    }
    int ans;
    top++;
    while (bottom <= top)
    {
        long long count = 0;
        int mid = (bottom + top) / 2;
        for (int i = 0; i < s; i++)
        {
            count += l[i] / mid;
        }
        // 파가 더 많이 소분되는 경우 => 파 길이를 더 늘리기
        if (count >= c)
        {
            ans = mid;
            bottom = mid + 1;
        }
        else
        {
            top = mid - 1;
        }
    }
    cout << sum - (long long)ans * c;

    return 0;
}