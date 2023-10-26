#include <iostream>
#include <deque>
using namespace std;
deque<deque<int>> xhq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<deque<int>> xhq;

    for (int i = 0; i < 4; i++)
    {
        string temp;
        cin >> temp;
        deque<int> dlatl;
        for (int j = 0; j < 8; j++)
        {
            dlatl.push_back(temp[j] - '0');
        }
        xhq.push_back(dlatl);
    }

    int rotate = 0;
    cin >> rotate;

    while (rotate--)
    {
        int num, direction;
        int flag[4] = {0, 0, 0, 0};
        cin >> num >> direction;
        flag[num - 1] = direction;

        // 왼쪽으로

        for (int i = num - 1; i > 0; i--)
        {

            if (xhq[i][6] != xhq[i - 1][2])
            {
                flag[i - 1] = flag[i] * -1;
            }
        }

        // 오른쪽으로
        for (int i = num - 1; i < 3; i++)
        {

            if (xhq[i][2] != xhq[i + 1][6])
            {
                flag[i + 1] = flag[i] * -1;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (flag[i] == 1)
            {
                int temp = xhq[i][7];
                xhq[i].pop_back();
                xhq[i].push_front(temp);
            }
            else if (flag[i] == -1)
            {
                int temp = xhq[i][0];
                xhq[i].pop_front();
                xhq[i].push_back(temp);
            }
        }
        // for (int i = 0; i < 4; i++)
        // {
        //     cout << i + 1 << " : ";

        //     for (int k : xhq[i])
        //     {
        //         cout << k << " ";
        //     }

        //     cout << "\n";
        // }
        // cout << "\n";
        // cout << "\n";
    }

    int wjatn = 1;
    int result = 0;
    for (int i = 0; i < 4; i++)
    {
        if (xhq[i][0] == 1)
        {
            result += wjatn;
        }
        wjatn *= 2;
    }

    cout << result;
    return 0;
}