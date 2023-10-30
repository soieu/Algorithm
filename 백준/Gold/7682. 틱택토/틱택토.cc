#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        // 입력 && 종료 조건
        string tictacto = "";
        cin >> tictacto;
        if (tictacto == "end")
            break;

        // 개수 확인
        int count_x = 0;
        int count_o = 0;

        for (int i = 0; i < 9; i++)
        {
            if (tictacto[i] == 'X')
            {
                count_x++;
            }
            else if (tictacto[i] == 'O')
            {
                count_o++;
            }
        }
        if (!((count_x == count_o + 1) || (count_x == count_o)))
        {
            cout << "invalid\n";
            continue;
        }

        // 승리 조건 확인
        int vic_x = 0;
        int vic_o = 0;

        // x 승리조건
        if (tictacto[0] == 'X' && tictacto[4] == 'X' && tictacto[8] == 'X')
        {
            vic_x++;
        }
        if (tictacto[2] == 'X' && tictacto[4] == 'X' && tictacto[6] == 'X')
        {
            vic_x++;
        }
        for (int i = 0; i < 3; i++)
        {
            if (tictacto[i] == 'X' && tictacto[i + 3] == 'X' && tictacto[i + 6] == 'X')
            {
                vic_x++;
            }
        }
        for (int i = 0; i < 8; i += 3)
        {
            if (tictacto[i] == 'X' && tictacto[i + 1] == 'X' && tictacto[i + 2] == 'X')
            {
                vic_x++;
            }
        }

        // o 승리조건
        if (tictacto[0] == 'O' && tictacto[4] == 'O' && tictacto[8] == 'O')
        {
            vic_o++;
        }
        if (tictacto[2] == 'O' && tictacto[4] == 'O' && tictacto[6] == 'O')
        {
            vic_o++;
        }
        for (int i = 0; i < 3; i++)
        {
            if (tictacto[i] == 'O' && tictacto[i + 3] == 'O' && tictacto[i + 6] == 'O')
            {
                vic_o++;
            }
        }
        for (int i = 0; i < 8; i += 3)
        {
            if (tictacto[i] == 'O' && tictacto[i + 1] == 'O' && tictacto[i + 2] == 'O')
            {
                vic_o++;
            }
        }
        if (vic_o > 0 && vic_x > 0)
        {
            cout << "invalid\n";
            continue;
        }
        else if (vic_o > 0 && count_o < count_x)
        {
            cout << "invalid\n";
            continue;
        }
        else if (vic_x > 0 && count_o + 1 != count_x)
        {
            cout << "invalid\n";
            continue;
        }
        else if (!(count_x == 5 && count_o == 4) && vic_o + vic_x == 0)
        {
            cout << "invalid\n";
            continue;
        }

        else
        {
            cout << "valid\n";
            continue;
        }
    }

    return 0;
}