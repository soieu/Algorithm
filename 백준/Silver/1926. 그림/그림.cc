#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[510][510] = {
    0,
};
int visited[510][510] = {
    0,
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int maxSize = 0;
int cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int y, x;
    cin >> y >> x;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> map[i][j];
        }
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (map[i][j] == 1 && visited[i][j] != 1)
            {
                q.push({i, j});
                int size = 0;
                cnt++;
                while (!q.empty())
                {
                    size++;

                    int yy = q.front().first, xx = q.front().second;
                    q.pop();
                    visited[yy][xx] = 1;

                    for (int k = 0; k < 4; k++)
                    {
                        int yyy;
                        int xxx;
                        yyy = yy + dy[k];
                        xxx = xx + dx[k];
                        if (yyy < y && xxx < x && yyy > -1 && xxx > -1 && visited[yyy][xxx] != 1 && map[yyy][xxx] == 1)
                        {
                            q.push({yyy, xxx});
                            visited[yyy][xxx] = 1;
                        }
                    }
                }
                if (size > maxSize)
                {
                    maxSize = size;
                }
            }
        }
    }
    cout << cnt << "\n"
         << maxSize << "\n";
    return 0;
}