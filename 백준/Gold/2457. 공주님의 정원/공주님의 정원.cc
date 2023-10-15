#include <iostream>
#include <vector>
using namespace std;
int arr[100005][4] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int basisStartMonth = 3;
    int basisStartDay = 1;
    int basisEndMonth = 11;
    int basisEndDay = 30;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    int preMonth = basisStartMonth;
    int preDay = basisStartDay;
    while (true)
    {
        int nxtMonth = preMonth;
        int nxtDay = preDay;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i][0] < preMonth || (arr[i][0] == preMonth && arr[i][1] <= preDay)) &&
                (arr[i][2] > nxtMonth || (arr[i][2] == nxtMonth && arr[i][3] > nxtDay)))
            {
                nxtMonth = arr[i][2];
                nxtDay = arr[i][3];
            }
        }
        if (preMonth == nxtMonth && preDay == nxtDay)
        {
            cout << 0;
            return 0;
        }
        count++;
        preMonth = nxtMonth;
        preDay = nxtDay;
        if (nxtMonth > basisEndMonth)
        {
            break;
        }
    }
    cout << count;

    return 0;
}