#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    set<int> set_temp;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        // 중복제거를 위해 자료구조 set 사용
        set_temp.insert(temp);
    }

    // 정렬해야해서 벡터로 set 옮겨담기
    vector<int> v(set_temp.begin(), set_temp.end());
    sort(v.begin(), v.end());

    vector<int> step;

    // 센서들의 간격 구하기
    for (int i = 1; i < v.size(); i++)
    {
        step.push_back(v[i] - v[i - 1]);
    }

    // 간격을 내림차순으로 정렬
    sort(step.begin(), step.end(), greater<>());

    int result = 0;
    for (int i = k - 1; i < step.size(); i++)
    {
        result += step[i];
    }

    cout << result;
    return 0;
}