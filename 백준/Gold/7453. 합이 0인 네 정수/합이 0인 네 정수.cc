#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long a[4001] = {0,};
long long b[4001] = {0,};
long long c[4001] = {0,};
long long d[4001] = {0,};
vector<long long> ab;
vector<long long> cd;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	cin>>n;
	
	for(int i = 0; i< n; i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	long long count = 0;

	for(int i = 0; i < ab.size(); i++){
        int idx = lower_bound(cd.begin(),cd.end(),-ab[i]) - cd.begin();
        int endIdx = upper_bound(cd.begin(),cd.end(),-ab[i]) - cd.begin();
        count += endIdx - idx;
    }

    cout << count;



	return 0;
}