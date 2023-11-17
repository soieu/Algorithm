#include <iostream>
#include <vector>
using namespace std;
int office[9][9] = {
    0,
};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> cctv;
int ans = 0x7fffffff;
int N, M;

void check(int x, int y, int dir)
{
    dir %= 4;
    while (1)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 1 || ny < 1 || nx > N || ny > M)
            return;
        if (office[nx][ny] == 6)
            return;
        if (office[nx][ny] != 0)
            continue;
        office[nx][ny] = -1;
    }
}
void dfs(int idx)
{
    // 백트래킹 한 단위 종료
    if (idx == cctv.size())
    {
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (!office[i][j])
                {
                    cnt++;
                }
            }
        }

        ans = min(ans, cnt);
        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int tmp[9][9];

    // 방향 4가지에 대해
    for (int dir = 0; dir < 4; dir++)
    {
        // 우선 tmp에 맵 복사
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                tmp[i][j] = office[i][j];
            }
        }

        // idx의 cctv에 대해
        if (office[x][y] == 1)
            check(x, y, dir);
        else if (office[x][y] == 2)
        {
            check(x, y, dir);
            check(x, y, dir + 2);
        }
        else if (office[x][y] == 3)
        {
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (office[x][y] == 4)
        {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        }
        else if (office[x][y] == 5)
        {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        dfs(idx + 1);
        // case 종료이므로 초기화 tmp에 office의 초기값을 담아넣어놨었음
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                office[i][j] = tmp[i][j];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> office[i][j];
            if (office[i][j] != 0 && office[i][j] != 6)
                cctv.push_back({i, j});
        }
    }

    dfs(0);
    cout << ans << '\n';
    return 0;
}