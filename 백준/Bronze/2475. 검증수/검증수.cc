#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int result = 0, temp;

    for(int i = 0; i < 5; i++) {
        cin >> temp;
        result += temp * temp; 
    }

    result %= 10;

    cout<<result;


    return 0;
}