#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;
    vector<int> houses;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        houses.push_back(temp);
    }

    // 정렬
    sort(houses.begin(), houses.end());

    // 간격 초기화 (간격 = 이분탐색 대상))
    int min_step = 1;
    int max_step = houses[houses.size() - 1] - houses[0];

    // 결과값 초기화
    int result_step = 0;

    while (min_step <= max_step)
    {
        // 현재 공유기 카운트
        int router_count = 1;

        // mid_step은 매번 변경됨
        int mid_step = (min_step + max_step) / 2;

        // 현재 가장 작은 간격 초기화
        int cur_step = max_step;

        int prev_house = houses[0];

        // 공유기 설치
        for (int i = 1; i < houses.size(); i++)
        {
            // 간격을 충족하는 집인경우
            if (houses[i] - prev_house >= mid_step)
            {
                router_count++;
                cur_step = min(cur_step, houses[i] - prev_house);
                prev_house = houses[i];
            }
        }

        // 공유기가 너무 많거나 같으면
        if (router_count >= c)
        {
            min_step = mid_step + 1;
            result_step = max(result_step, cur_step);
        }
        // 공유기가 적거나 동일하면
        else
        {
            max_step = mid_step - 1;
        }
    }
    cout << result_step;

    return 0;
}