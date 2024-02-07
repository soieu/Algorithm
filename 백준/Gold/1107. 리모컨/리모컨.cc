#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> brokenButtons = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int targetChannel, currentChannel = 100, brokenButtonCount = 0;
int clickCount, targetDigit;

void solve(int len, int idx, string num)
{
    if(len == idx)
    {
        clickCount = min(clickCount, abs(targetChannel - stoi(num)) + len);
    }
    else if(len + 1 == idx)
    {
        clickCount = min(clickCount, abs(targetChannel - stoi(num)) + len + 1);
        return;
    }
    else if(len - 1 == idx && idx != 0)
    {
        clickCount = min(clickCount, abs(targetChannel - stoi(num)) + len - 1);
    }
    
    

    for(int i = 0; i < brokenButtons.size(); i++)
    {
        num.push_back(brokenButtons[i]+'0');
        solve(len, idx + 1, num);
        num.pop_back();
    }

}

int digit(int num) 
{
    int count = 0;
    while(num)
    {
        num = num / 10;
        count++;
    }
    return count;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>targetChannel>>brokenButtonCount;

    for(int i=0; i<brokenButtonCount; i++)
    {
        int temp;
        cin>>temp;
        brokenButtons.erase(remove(brokenButtons.begin(), brokenButtons.end(), temp), brokenButtons.end());
    }

    clickCount = abs(targetChannel - currentChannel);

    if (targetChannel == 0)
    {
        targetDigit = 1;
    }
    else
    {
        targetDigit = digit(targetChannel);

    }

    solve(targetDigit, 0, "");

    cout << clickCount;


    return 0;
}