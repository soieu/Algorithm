#include <iostream>
#include <queue>
using namespace std;
char map[5][5];
int result = 0;
int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {1, -1, 0, 0};
int visited[5][5] = {
    0,
};

queue<pair<int, int>> q;

void bfs(int x, int y)
{
    int bfs_visited[5][5] = {
        0,
    };
    q.push({y, x});

    int cnt = 1;
    bfs_visited[y][x] = 1;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dy = y + dir_y[i];
            int dx = x + dir_x[i];
            if (visited[dy][dx] == 1 && bfs_visited[dy][dx] == 0 && dy > -1 && dx > -1 && dy < 5 && dx < 5)
            {
                bfs_visited[dy][dx] = 1;
                q.push({dy, dx});
                cnt++;
            }
        }
    }
    if (cnt < 7)
    {
        return;
    }
    else
    {
        // cout << "============== 합격 =============\n";
        // for (int i = 0; i < 5; i++)
        // {
        //     for (int j = 0; j < 5; j++)
        //     {
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "=================================\n";
        result++;
        return;
    }
}
void backTrack(int len, int s_count, int x, int y)
{
    if (len == 7 && s_count >= 4)
    {
        bfs(x, y);
        return;
    }
    // 4 -> 1,2,3,4만 가능 5-> 2,3,4만 가능

    for (int i = y; i < 5; i++)
    {
        for (int j = (i == y ? x + 1 : 0); j < 5; j++)
        {
            if (map[i][j] == 'S')
            {
                visited[i][j] = 1;

                backTrack(len + 1, s_count + 1, j, i);
                visited[i][j] = 0;
            }
            else
            {
                if (len + 1 >= 4 && s_count < len - 2)
                {
                    continue;
                }
                visited[i][j] = 1;
                backTrack(len + 1, s_count, j, i);
                visited[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> map[i][j];
        }
    }

    backTrack(0, 0, -1, 0);
    cout << result;
    return 0;
}