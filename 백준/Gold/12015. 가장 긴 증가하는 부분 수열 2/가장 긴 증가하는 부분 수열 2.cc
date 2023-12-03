#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int temp;    // 들어오는 값
    int idx = 0; // 인덱스

    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        // 첫 값을 입력받을 때
        if (idx == 0)
        {
            L[idx++] = temp;
        }
        else
        {
            // 마지막 값보다 현재 값이 클 때 L에 추가 & 인덱스 증가
            if (L[idx - 1] < temp)
            {
                L[idx++] = temp;
            }
            //
            else
            {
                // 현재 값이 들어갈 곳에 값 넣음
                L[lower_bound(L, L + idx, temp) - L] = temp;
            }
        }
    }
    cout << idx;
    return 0;
}