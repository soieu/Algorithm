#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    int num = 0;
    int result = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            num *= 10;
            num += input[i] - '0';
        }
        else if (input[i] == '+')
        {
            result += num;
            num = 0;
        }
        else if (input[i] == '-')
        {
            result += num;
            num = 0;
            int numnum = 0;
            int resultresult = 0;
            for (int j = i + 1; j < input.length(); j++)
            {
                if (input[j] >= '0' && input[j] <= '9')
                {
                    numnum *= 10;
                    numnum += input[j] - '0';
                }
                else if (input[j] == '+' || input[j] == '-')
                {
                    resultresult += numnum;
                    numnum = 0;
                }

                if (input.length() - 1 == j)
                {
                    resultresult += numnum;
                    result -= resultresult;
                    i = input.length();
                    break;
                }
            }
        }
        if (input.length() - 1 == i)
        {
            result += num;
        }
    }
    cout << result;

    return 0;
}