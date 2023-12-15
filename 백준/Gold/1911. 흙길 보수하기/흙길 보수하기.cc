#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int>> planks;

    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        int s, l;
        cin >> s >> l;
        planks.push_back({s, l});
    }
    sort(planks.begin(), planks.end());

    int plank_count = 0;
    int plank_start = 0;
    for (int plank_index = 0; plank_index < planks.size(); plank_index++)
    {
        int plank_size;
        if (plank_start == 0 || plank_start <= planks[plank_index].first)
        {
            plank_size = planks[plank_index].second - planks[plank_index].first;
        }
        else // 이전에 남은 부분이 있고 그게 걸쳐지는 경우
        {
            plank_size = planks[plank_index].second - plank_start;
        }
        plank_count += plank_size / l + (plank_size % l > 0 ? 1 : 0);
        plank_start = planks[plank_index].second + l * (plank_size / l + (plank_size % l > 0 ? 1 : 0)) - plank_size;
    }
    cout << plank_count;

    return 0;
}