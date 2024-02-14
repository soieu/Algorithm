#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    map<string, string> passwords;

    cin>>n>>m;

    for(int i = 0; i < n; i++) 
    {
        string a, b;
        cin>>a>>b;
        passwords.insert({a, b});
    }

    for(int i = 0; i < m; i++)
    {
        string a;
        cin>>a;
        cout<<passwords[a]<<"\n";
    }

    return 0;
}