#include <iostream>
#include <queue>
using namespace std;
int zero_flag = 0;
int two_flag = 0;
int n, m;
int map[301][301] = {
    0,
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;
queue<pair<int, int>> q_zero;

void bfs()
{
    int region = 0;
    int visited[301][301] = {
        0,
    };

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (map[i][j] == 0)
                q_zero.push({i, j});
            if (visited[i][j] == 0 && map[i][j] > 0)
            {
                q.push({i, j});
                region++;
                visited[i][j] = 1;
                while (!q.empty())
                {
                    int prev_n = q.front().first;
                    int prev_m = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int p_n = prev_n + dy[k];
                        int p_m = prev_m + dx[k];

                        if (p_n < 1 || p_m < 1 || p_n > n - 1 || p_m > m - 1 || visited[p_n][p_m] == 1 || map[p_n][p_m] == 0)
                            continue;
                        q.push({p_n, p_m});
                        visited[p_n][p_m] = 1;
                    }
                }
            }
        }
    }
    if (region >= 2)
    {
        two_flag = 1;
    }
}
void melt()
{
    if (q_zero.size() == m * n - 2 * m - 2 * n + 4)
    {
        zero_flag = 1;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                q_zero.push({i, j});
            }
        }
    }

    while (!q_zero.empty())
    {
        int prev_n = q_zero.front().first;
        int prev_m = q_zero.front().second;
        q_zero.pop();
        for (int k = 0; k < 4; k++)
        {
            int p_n = prev_n + dy[k];
            int p_m = prev_m + dx[k];

            if (p_n < 1 || p_m < 1 || p_n > n - 1 || p_m > m - 1 || map[p_n][p_m] == 0)
                continue;
            map[p_n][p_m]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int result = 0;
    int year = -1;
    while (!zero_flag && !two_flag)
    {
        bfs();
        melt();
        year++;
    }
    if (two_flag == 1)
        result = year;

    cout << result;

    return 0;
}