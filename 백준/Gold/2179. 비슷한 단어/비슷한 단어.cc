#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string str[20001];
    int idxa = -1, idxb = -1;
    int maxlen = 0;
    int len = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // 중복 확인
            if (str[i] == str[j])
            {
                continue;
            }
            // cout << "ok" << endl;

            // 길이 비교
            if (str[i].length() < maxlen || str[j].length() < maxlen)
            {
                continue;
            }
            // cout << "ko" << endl;
            for (int k = 0; k < str[i].length(); k++)
            {

                // 다른 단어가 나오는 경우
                if (str[i][k] != str[j][k])
                {
                    break;
                }
                else if (k > maxlen)
                {
                    maxlen = k;
                    idxa = i;
                    idxb = j;
                }
                else if (len == 0)
                {
                    len = 1;
                    idxa = i;
                    idxb = j;
                }
            }
        }
    }

    cout << str[idxa] << "\n"
         << str[idxb];
    return 0;
}