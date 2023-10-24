#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dp[510][510] = {
    0,
};
int map[510][510] = {
    0,
};

int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {1, -1, 0, 0};
int m, n;

int dfs(int y, int x)
{
    if (y == m - 1 && x == n - 1)
    {
        return 1;
    }

    if (dp[y][x] != -1)
        return dp[y][x];
    dp[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = dir_y[i] + y;
        int nx = dir_x[i] + x;
        if (nx >= 0 && ny >= 0 && nx < n && ny < m)
        {
            if (map[ny][nx] < map[y][x])
            {
                dp[y][x] = dp[y][x] + dfs(ny, nx);
            }
        }
    }
    return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    fill(&dp[0][0], &dp[509][510], -1);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    cout << dfs(0, 0);

    return 0;
}
