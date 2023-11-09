#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

int map[501][501] = {
    0,
};
int visited[501][501] = {
    0,
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void map_fill(int num, int x1, int y1, int x2, int y2)
{
    int s_x = min(x1, x2);
    int e_x = max(x1, x2);
    int s_y = min(y1, y2);
    int e_y = max(y1, y2);
    for (int i = s_y; i <= e_y; i++)
    {
        for (int j = s_x; j <= e_x; j++)
        {
            map[i][j] = num;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x1, y1, x2, y2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        map_fill(1, x1, y1, x2, y2);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        map_fill(2, x1, y1, x2, y2);
    }

    deque<tuple<int, int, int>> dq; // {y, x, w}

    int result = -1;

    dq.push_front({0, 0, 0}); // 현재 위치 삽입
    visited[0][0] = 1;        // 방문 표시
    while (!dq.empty())
    {
        auto present = dq.front(); // 현재위치
        dq.pop_front();
        if (get<0>(present) == 500 && get<1>(present) == 500)
        {
            result = get<2>(present);
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int yy = get<0>(present) + dy[i];
            int xx = get<1>(present) + dx[i];

            // 못가는곳 제외
            if (yy < 0 || xx < 0 || yy > 500 || xx > 500 || map[yy][xx] == 2 || visited[yy][xx] == 1)
                continue;
            if (map[yy][xx] == 1)
            {
                dq.push_back({yy, xx, get<2>(present) + 1});
            }
            if (map[yy][xx] == 0)
            {
                dq.push_front({yy, xx, get<2>(present)});
            }
            visited[yy][xx] = 1;
        }
    }
    cout << result;

    return 0;
}