#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int result = 0;

    if (n < 100) {
		result =  n;
	} else {
		result = 99;
 
		for (int i = 100; i <= n; i++) {
			int bak = i / 100;		 
			int sip = (i / 10) % 10; 
			int ill = i % 10;
 
			if ((bak - sip) == (sip - ill)) { 
				result++;
			}
		}
	}

    cout<<result;

    return 0;
}