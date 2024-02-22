#include <iostream>
#include <vector>
using namespace std;

vector<string> strs;
int max_count = 0;

int n, k;
// a, b, c ...

void backtracking(int idx, bool alp[], int alph)
{
    // 사용하는 알파벳들이 결정됐을 때.
    if (alph == k)
    {
        int count = 0;

        // 문자 배열
        for (int i = 0; i < n; i++)
        {
            int flag = 0;
            // 문자열 체크
            for (int j = 0; j < strs[i].size(); j++)
            {
                if (alp[strs[i][j] - 'a'] != 1)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                count++;
            }
        }

        if (count == n)
        {
            cout << count;
            exit(0);
        }
        max_count = max(max_count, count);
        return;
    }

    // alpha 만들기

    for (int j = idx; j < 26; j++)
    {
        if (!alp[j])
        {
            alp[j] = true;
            backtracking(j + 1, alp, alph + 1);
            alp[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool alpha[] = {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};

    cin >> n >> k;

    if (k < 5)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        temp = temp.substr(4, temp.size() - 8);
        strs.push_back(temp);
    }

    backtracking(0, alpha, 5);

    cout << max_count;

    return 0;
}