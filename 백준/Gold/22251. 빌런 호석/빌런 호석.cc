#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n, k, p, x;
int result = 0;
vector<bool> v[10] = {
    {true, true, true, true, true, true, false},     // 0
    {false, true, true, false, false, false, false}, // 1
    {true, true, false, true, true, false, true},    // 2
    {true, true, true, true, false, false, true},    // 3
    {false, true, true, false, false, true, true},   // 4
    {true, false, true, true, false, true, true},    // 5
    {true, false, true, true, true, true, true},     // 6
    {true, true, true, false, false, false, false},  // 7
    {true, true, true, true, true, true, true},      // 8
    {true, true, true, true, false, true, true},     // 9
};
int diff(int i, int x)
{
    int led = 0;

    // 10 ~ 10^k 자리수
    for (int j = 0; j < k; j++)
    {
        int a = i % 10;
        int b = x % 10;
        for (int k = 0; k < 7; k++)
        {
            if (v[a][k] != v[b][k])
            {
                led++;
            }
        }
        i /= 10;
        x /= 10;
    }

    return led;
}
void solution()
{
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;
        // i와 x의 led 차이가, p보다 작은 경우 경우의 수 증가
        if (diff(i, x) <= p)
            result++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 반전시킬 led를 고를 수 있는 경우의 수
    // n층까지 있고, k자리의 수가 있음. 1~p개 반전이 가능하고 현재 엘레베이터는 x층
    cin >> n >> k >> p >> x;

    solution();
    cout << result;

    return 0;
}
