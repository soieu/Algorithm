#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));

vector<pair<int, int>> eee;

bool isValid(int row, int col, int num, int arr[9][9])
{
    // 여기에 num이 row, col 위치에 유효한지 검사하는 로직 추가
    return true; // 예시로 항상 true를 반환하도록 설정
}

void solve(int idx, vector<vector<int>> &arr)
{ // 참조를 사용하여 arr 수정
    if (idx == eee.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0); // 정답을 찾으면 프로그램 종료
    }

    int x = eee[idx].first;
    int y = eee[idx].second;

    for (int i = 1; i <= 9; i++)
    { // 1부터 9까지의 숫자 시도
        bool flag = true;
        // 가로세로검사
        for (int j = 0; j < 9; j++)
        {
            if (arr[x][j] == i || arr[j][y] == i)
            {
                flag = false;
                break;
            }
        }
        // 정사각형 검사
        if (flag)
        {
            for (int j = 0; j < 3 && flag; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    int xx = (x / 3) * 3 + j;
                    int yy = (y / 3) * 3 + k;
                    if (arr[xx][yy] == i)
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag)
        {
            arr[x][y] = i;
            solve(idx + 1, arr);
            arr[x][y] = 0; // 백트래킹
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
            {
                eee.push_back({i, j});
            }
        }
    }

    solve(0, sudoku);

    return 0;
}