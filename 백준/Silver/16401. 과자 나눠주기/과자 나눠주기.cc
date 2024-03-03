#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<int> v(n);
    int start = 1; // 시작 값을 1로 설정, 0으로 설정할 경우 무한 루프에 빠질 수 있음
    int end = 0;   // 최댓값 초기화
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        end = max(end, v[i]);
    }
    sort(v.begin(), v.end());

    int result = 0; // 결과값 저장 변수
    while (start <= end)
    { // 이진 탐색 조건 수정
        int mid = (start + end) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += v[i] / mid;
        }
        if (count >= m)
        {
            result = mid;    // 조건을 만족하는 mid 값을 결과값으로 저장
            start = mid + 1; // 조건을 만족하는 경우 start 업데이트
        }
        else
        {
            end = mid - 1; // 조건을 만족하지 않는 경우 end 업데이트
        }
    }

    cout << result; // 수정된 결과값 출력
    return 0;
}
