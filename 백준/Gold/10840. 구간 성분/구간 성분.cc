#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    set<vector<int>> alphabet_count;
    string a, b;
    int result = 0;

    cin>>a>>b;


    // a의 부분 문자열을 vector에 표시 후 set에 넣기
    for(int last = 1; last <= a.length(); last++) 
    {

        vector<int> alphabet(26, 0);
        // 전체 만들고 후에 하나씩 빼기
        for(int i = 0; i < last;i++)
        {
            alphabet[a[i]-'a']++;
        }
        alphabet_count.insert(alphabet);
        for(int i = 0; i < last - 1; i++)
        {
            alphabet[a[i]-'a']--;
            alphabet_count.insert(alphabet);
        }
    }

    // b의 부분 문자열을 vector에 표시 후 set과 비교
        // b의 부분 문자열을 vector에 표시 후 set과 비교
    for(int last = 1; last <= b.length(); last++) 
    {

        vector<int> alphabet(26, 0);
        // 전체 만들고 후에 하나씩 빼기
        for(int i = 0; i < last;i++)
        {
            alphabet[b[i]-'a']++;
        }
        alphabet_count.count(alphabet);
        if(alphabet_count.count(alphabet))
        {
            result = max(result, last);
        }
        for(int i = 0; i < last - 1; i++)
        {
            alphabet[b[i]-'a']--;
            alphabet_count.count(alphabet);
            if(alphabet_count.count(alphabet))
            {
                result = max(result, last - i - 1);
            }
        }
    }


    cout<<result;

    return 0;
}