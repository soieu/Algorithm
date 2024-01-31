#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

//          하 상 뒤 앞 좌 우
int x_dir[] = {-1, 1, 0, 0, 0, 0};
int y_dir[] = {0, 0, -1, 1, 0, 0};
int z_dir[] = {0, 0, 0, 0, -1, 1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n, h, count = 1;

	cin >> m >> n >> h;

	int tomato[102][102][102];  // 입력받음 -> 토마토 상태
	int visited[102][102][102];	// 방문함

    fill_n(&visited[0][0][0], 102 * 102 * 102, 0);
	queue<tuple<int, int, int>> q; // 큐큐큐

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{

				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
				{
					q.push(make_tuple(i, j, k));
					visited[i][j][k] = 1;
				}
			}
		}
	}

    while (!q.empty()) {
        auto [z, y, x] = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + x_dir[i];
            int ny = y + y_dir[i];
            int nz = z + z_dir[i];
            
            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < m && ny < n && nz < h && tomato[nz][ny][nx] == 0 && visited[nz][ny][nx] == 0) {
                q.push(make_tuple(nz, ny, nx));
                visited[nz][ny][nx] = 1;
                tomato[nz][ny][nx] = tomato[z][y][x] + 1;
            }
        }
    }
    int days = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (tomato[i][j][k] == 0) {
                    cout << "-1\n";
                    return 0;
                }
                days = max(days, tomato[i][j][k]);
            }
        }
    }

    cout << days - 1 << '\n'; // 첫 날을 제외하고 계산

	return 0;
}