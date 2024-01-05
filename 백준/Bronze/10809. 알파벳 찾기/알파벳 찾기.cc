#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    for (int i = 0; i < 26; i++)
    {
        bool found = false;
        for (int idx = 0; idx < s.length(); idx++)
        {
            if (char('a' + i) == s[idx])
            {
                cout << idx << " ";
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "-1 ";
        }
    }

    return 0;
}