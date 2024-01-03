#include <iostream>

using namespace std;

int main() {
    int n, a, k=0;
    cin >> n;
    if(n==0){
        cout<<1;
        return 0;
    }
    a=n;
    while(true)
    {
        a=10*(a%10)+((a/10)+(a%10))%10;
        k++;
        if(a==n)
        {
            break;
        }
    }
    cout << k;
    
    return 0;
}