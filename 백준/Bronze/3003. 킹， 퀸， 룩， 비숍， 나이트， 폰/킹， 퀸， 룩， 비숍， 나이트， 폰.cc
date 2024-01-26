#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int white_pieces[] = {1,1,2,2,2,8};

    for(int i = 0; i < 6; i++)
    {
        int temp;
        cin>>temp;
        cout << white_pieces[i] - temp<<" ";
    }

    return 0;
}