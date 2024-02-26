#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> costs;

int solve(int mid)
{
    int count = 1;     // 시작할 때 하나의 그룹이 필요함
    int remains = mid; // 현재 그룹에 할당할 수 있는 남은 비용

    for (int cost : costs)
    {
        if (cost > remains)
        {                         // 현재 그룹에 비용을 할당할 수 없는 경우 새 그룹 시작
            count++;              // 그룹 수 증가
            remains = mid - cost; // 새 그룹의 남은 비용 초기화
        }
        else
        {
            remains -= cost; // 현재 그룹에 비용 할당
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int top = 0;
    int bottom = 0;

    for (int i = 0; i < n; i++)
    {
        int cost;
        cin >> cost;
        costs.push_back(cost);
        top = max(top, cost); // 가장 큰 비용을 찾음
        bottom += cost;       // 모든 비용의 합을 계산
    }

    int result = bottom; // 가능한 최대 비용
    while (top <= bottom)
    {
        int mid = top + (bottom - top) / 2;
        if (solve(mid) <= m)
        {                     // m개 이하의 그룹으로 가능한 경우
            result = mid;     // 결과 업데이트
            bottom = mid - 1; // 더 낮은 비용을 찾기 위해 범위 조정
        }
        else
        {
            top = mid + 1; // 더 높은 비용으로 범위 조정
        }
    }

    cout << result; // 최적의 해 출력

    return 0;
}
