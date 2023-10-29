#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

int map[51][51] = {
    0,
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> q_bfs;
queue<pair<int, int>> q_disk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, R;
    cin >> N >> L >> R;
    int days = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    bool flag = true;
    while (flag)
    {
        int visited[51][51] = {
            0,
        };

        // 인구이동 확인
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {

                if (visited[i][j] == 0)
                {
                    int population = 0;
                    int regions = 0;
                    q_bfs.push({i, j});
                    q_disk.push({i, j});
                    visited[i][j] = 1;
                    population += map[i][j];
                    regions++;

                    while (!q_bfs.empty())
                    {
                        int y = q_bfs.front().first;
                        int x = q_bfs.front().second;
                        q_bfs.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            int ckdl = abs(map[y][x] - map[ny][nx]);
                            if ((nx > -1 && nx < N && ny > -1 && ny < N) && (ckdl >= L && ckdl <= R) && visited[ny][nx] == 0)
                            {
                                population += map[ny][nx];
                                regions++;
                                visited[ny][nx] = 1;
                                q_bfs.push({ny, nx});
                                q_disk.push({ny, nx});
                                flag = false;
                            }
                        }
                    }
                    // bfs 종료 -> 인구이동
                    if (q_disk.size() > 1)
                    {

                        while (!q_disk.empty())
                        {
                            int y = q_disk.front().first;
                            int x = q_disk.front().second;
                            q_disk.pop();
                            map[y][x] = population / regions;
                        }
                    }
                    else
                    {
                        q_disk.pop();
                    }
                }
            }
        }
        // 한 단계 종료
        if (flag == false)
        {
            flag = true;
            days++;
        }
        else
        {
            flag = false;
        }
    }

    cout << days;

    return 0;
}