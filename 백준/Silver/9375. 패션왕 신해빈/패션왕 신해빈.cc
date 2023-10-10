#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int case_count = 1;
        map<string, int> clothing;
        map<string, int>::iterator iter;
        for (int i = 0; i < n; i++)
        {
            string detail;
            string type;
            cin >> detail >> type;
            if (clothing.find(type) != clothing.end())
            {
                clothing[type]++;
            }
            else
            {
                clothing[type] = 1;
            }
        }
        for (iter = clothing.begin(); iter != clothing.end(); iter++)
        {

            int val = iter->second;
            case_count = case_count * (val + 1);
        }
        cout << case_count - 1 << "\n";
    }
    return 0;
}