#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string from;
string playing;
string to;
int n;
int result = 0x7fffffff;

void turnon(int cur)
{
    playing = from;
    int count = 0;

    // 0번 스위치를 누르는 경우
    if (cur == 0)
    {
        playing[0] = playing[0] == '0' ? '1' : '0';
        playing[1] = playing[1] == '0' ? '1' : '0';
        count++;
        cur++;
    }

    // 일반적인 상황 !
    while (cur < n)
    {
        // 목표와 동일하지 않다면 조건에 맞는 경우 스위치 누르기
        if (playing[cur - 1] != to[cur - 1])
        {
            playing[cur - 1] = playing[cur - 1] == '0' ? '1' : '0';
            playing[cur] = playing[cur] == '0' ? '1' : '0';
            if (cur < n - 1)
            {
                playing[cur + 1] = playing[cur + 1] == '0' ? '1' : '0';
            }
            count++;
        }
        // 목표와 동일한지 확인
        if (playing == to)
        {
            result = min(result, count);
            break;
        }
        cur++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> from >> to;

    turnon(0);
    turnon(1);
    if (result == 0x7fffffff)
    {
        cout << "-1";
    }
    else
    {
        cout << result;
    }

    return 0;
}