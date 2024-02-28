#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int top = 0; // 최대 타일 값을 저장
int n;       // 보드의 크기

bool isEqual(const vector<vector<int>> &a, const vector<vector<int>> &b)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

// 타일을 오른쪽으로 이동시키는 함수
bool moveRight(vector<vector<int>> &board)
{
    vector<vector<int>> before = board;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (board[i][j] == 0)
                continue;
            int k = j;
            while (k + 1 < n && board[i][k + 1] == 0)
            {
                board[i][k + 1] = board[i][k];
                board[i][k] = 0;
                k++;
            }
        }
        for (int j = n - 1; j > 0; j--)
        {
            if (board[i][j] == board[i][j - 1])
            {
                board[i][j] *= 2;
                board[i][j - 1] = 0;
                top = max(top, board[i][j]);
                j--;
            }
        }
        for (int j = n - 2; j >= 0; j--)
        {
            if (board[i][j] == 0)
                continue;
            int k = j;
            while (k + 1 < n && board[i][k + 1] == 0)
            {
                board[i][k + 1] = board[i][k];
                board[i][k] = 0;
                k++;
            }
        }
    }
    return !isEqual(before, board);
}

// 타일을 왼쪽으로 이동시키는 함수
bool moveLeft(vector<vector<int>> &board)
{
    vector<vector<int>> before = board;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            int k = j;
            while (k - 1 >= 0 && board[i][k - 1] == 0)
            {
                board[i][k - 1] = board[i][k];
                board[i][k] = 0;
                k--;
            }
        }
        for (int j = 0; j < n - 1; j++)
        {
            if (board[i][j] == board[i][j + 1])
            {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
                top = max(top, board[i][j]);
                j++;
            }
        }
        for (int j = 1; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            int k = j;
            while (k - 1 >= 0 && board[i][k - 1] == 0)
            {
                board[i][k - 1] = board[i][k];
                board[i][k] = 0;
                k--;
            }
        }
    }
    return !isEqual(before, board);
}

// 타일을 위로 이동시키는 함수
bool moveUp(vector<vector<int>> &board)
{
    vector<vector<int>> before = board;
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if (board[i][j] == 0)
                continue;
            int k = i;
            while (k - 1 >= 0 && board[k - 1][j] == 0)
            {
                board[k - 1][j] = board[k][j];
                board[k][j] = 0;
                k--;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (board[i][j] == board[i + 1][j])
            {
                board[i][j] *= 2;
                board[i + 1][j] = 0;
                top = max(top, board[i][j]);
                i++;
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (board[i][j] == 0)
                continue;
            int k = i;
            while (k - 1 >= 0 && board[k - 1][j] == 0)
            {
                board[k - 1][j] = board[k][j];
                board[k][j] = 0;
                k--;
            }
        }
    }
    return !isEqual(before, board);
}

// 타일을 아래로 이동시키는 함수
bool moveDown(vector<vector<int>> &board)
{
    vector<vector<int>> before = board;
    for (int j = 0; j < n; j++)
    {
        for (int i = n - 2; i >= 0; i--)
        {
            if (board[i][j] == 0)
                continue;
            int k = i;
            while (k + 1 < n && board[k + 1][j] == 0)
            {
                board[k + 1][j] = board[k][j];
                board[k][j] = 0;
                k++;
            }
        }
        for (int i = n - 1; i > 0; i--)
        {
            if (board[i][j] == board[i - 1][j])
            {
                board[i][j] *= 2;
                board[i - 1][j] = 0;
                top = max(top, board[i][j]);
                i--;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (board[i][j] == 0)
                continue;
            int k = i;
            while (k + 1 < n && board[k + 1][j] == 0)
            {
                board[k + 1][j] = board[k][j];
                board[k][j] = 0;
                k++;
            }
        }
    }
    return !isEqual(before, board);
}

void btrk(int idx, vector<vector<int>> &v)
{
    if (idx == 5)
    {
        return;
    }
    vector<vector<int>> a = v;
    if (moveRight(a))
        btrk(idx + 1, a);
    vector<vector<int>> b = v;
    if (moveLeft(b))
        btrk(idx + 1, b);
    vector<vector<int>> c = v;
    if (moveUp(c))
        btrk(idx + 1, c);
    vector<vector<int>> d = v;
    if (moveDown(d))
        btrk(idx + 1, d);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            top = max(top, map[i][j]);
        }
    }

    btrk(0, map);
    cout << top;
    return 0;
}
