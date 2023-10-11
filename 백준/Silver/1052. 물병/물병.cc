#include <iostream>
#include <vector>
using namespace std;

// if k = 1000이면?  => 결국 1  / 1 1 1 1 / 1 1 1 1 비스무리하게 종결
// 언제 -1이 나오지???????
// -1이 나오는 경우 : k가 11 1111 1111 이상인경우, 즉 k  1024 512  / 256 128 64 32 / 16 4 2 1
// 만약 n이 11이면 : 1011 -> k가 2인 경우 +1 해가면서 1이 2개되는 경우 찾기 !
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    int oneCount = 0;
    int result = 0; // 몇개의 물병이 더 필요한지?
    cin >> n >> k;

    while (true)
    {
        int count = 0; // 1 몇개인지 세고 k랑 비교
        for (int i = 0; (1 << i) < n; i++)
        {
            if (n & (1 << i))
            {
                count++;
            }
        }
        if (count <= k)
            break;
        result++;
        n++;
    }
    cout << result;
    return 0;
}