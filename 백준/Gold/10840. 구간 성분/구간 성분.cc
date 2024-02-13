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
    for(int i = 1; i <= a.length(); i++) 
    {
        int last = i;
        int start = i - 1;

        for(int len = last; len > 0; len--)
        {
            vector<int> alphabet(26, 0);
            for(int count = 0 ; count < len; count++)
            {
                alphabet[a[start-count] - 'a']++;
            }
            alphabet_count.insert(alphabet);
        }
    }

    // b의 부분 문자열을 vector에 표시 후 set과 비교
    for(int i = 1; i <= b.length(); i++) 
    {
        int last = i;
        int start = i - 1;

        for(int len = last; len > 0; len--)
        {
            vector<int> alphabet(26, 0);
            for(int count = 0 ; count < len; count++)
            {
                alphabet[b[start-count] - 'a']++;
            } 
            if(alphabet_count.count(alphabet))
            {
                result = max(result, len);
            }
        }
    }

    cout<<result;

    return 0;
}