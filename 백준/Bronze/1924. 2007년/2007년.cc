#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int a, int b)
{
    string answer = "";
    vector<string> weekday = {
        "MON",
        "TUE",
        "WED",
        "THU",
        "FRI",
        "SAT",
        "SUN"};
    vector<int> month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int past_days = 0;

    for (int i = 0; i < a - 1; ++i)
    {
        past_days += month_days[i];
    }

    past_days += b - 1;

    answer = weekday[(past_days) % 7];

    return answer;
}

int main()
{
    int month, day;
    cin >> month >> day;

    string dayOfWeek = solution(month, day);
    cout << dayOfWeek;

    return 0;
}
