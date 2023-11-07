#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <set>

#define MAX 20
using namespace std;

int row, col;
char map[MAX][MAX] = {
    0,
};
int alphabet[26] = {
    0,
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int result = 0;

void dfs(int x, int y, int cnt)
{
    result = max(result, cnt);

    alphabet[map[x][y] - 'A'] = 1; // 방문 처리

    for (int i = 0; i < 4; i++)
    {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if (nX < 0 || nX >= row || nY < 0 || nY >= col)
            continue;

        int alpha_index = map[nX][nY] - 'A';

        if (alphabet[alpha_index] == 0)
        {
            dfs(nX, nY, cnt + 1);
            alphabet[alpha_index] = 0; // dfs에서 방문처리 후 초기화
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> map[i][j];

    alphabet[map[0][0] - 'A'] = 1;

    dfs(0, 0, 1);

    cout << result;

    return 0;
}