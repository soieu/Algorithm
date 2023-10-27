#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void act(string s, string t)
{
    string sss;
    if (s == t)
    {
        cout << 1;
        exit(0);
    }
    if (s.size() > t.size())
        return;
    if (t.back() == 'A')
    {
        sss = t;
        sss.pop_back();
        act(s, sss);
    }
    if (t.front() == 'B')
    {
        sss = t;
        reverse(sss.begin(), sss.end());
        sss.pop_back();
        act(s, sss);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    act(s, t);

    cout << 0;
    return 0;
}