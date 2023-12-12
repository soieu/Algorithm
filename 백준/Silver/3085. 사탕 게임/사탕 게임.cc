#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char board[51][51];
int visited[51][51] = {
    0,
};
int dir_x[4] = {0, 0, 1, -1};
int dir_y[4] = {1, -1, 0, 0};
int result_count = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    char temp;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            board[i][j] = temp[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 1;
            for (int k = 0; k < 4; k++)
            {
                int next_x = j + dir_x[k];
                int next_y = i + dir_y[k];
                if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
                    continue;
                if (visited[next_y][next_x] == 1)
                    continue;
                if (board[next_y][next_x] == board[i][j])
                    continue;
                char temp_board[51][51];
                // 맵 바꾸고
                for (int a = 0; a < n; a++)
                {
                    for (int b = 0; b < n; b++)
                    {
                        if (a == i && b == j)
                        {
                            temp_board[a][b] = board[next_y][next_x];
                        }
                        else if (a == next_y && b == next_x)
                        {
                            temp_board[a][b] = board[i][j];
                        }
                        else
                        {
                            temp_board[a][b] = board[a][b];
                        }
                    }
                }
                for (int a = 0; a < n; a++)
                {
                    char start;
                    int color_count;
                    for (int b = 0; b < n; b++)
                    {
                        if (b == 0)
                        {
                            start = temp_board[a][b];
                            color_count = 1;
                        }
                        else
                        {
                            if (start != temp_board[a][b])
                            {
                                result_count = max(result_count, color_count);
                                start = temp_board[a][b];
                                color_count = 1;
                            }
                            else
                            {
                                color_count++;
                            }
                        }
                    }
                    result_count = max(result_count, color_count);

                    if (result_count == n)
                    {
                        cout << result_count;
                        return 0;
                    }
                }
                for (int a = 0; a < n; a++)
                {
                    char start;
                    int color_count;
                    for (int b = 0; b < n; b++)
                    {
                        if (b == 0)
                        {
                            start = temp_board[b][a];
                            color_count = 1;
                        }
                        else
                        {
                            if (start != temp_board[b][a])
                            {
                                result_count = max(result_count, color_count);
                                start = temp_board[b][a];
                                color_count = 1;
                            }
                            else
                            {
                                color_count++;
                            }
                        }
                    }
                    result_count = max(result_count, color_count);

                    if (result_count == n)
                    {
                        cout << result_count;
                        return 0;
                    }
                }
            }
        }
    }

    cout << result_count;

    return 0;
}