#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> v;


	int num;
	for(int i = 0; i < 10; i++)
	{
		cin>>num;
		v.push_back(num%42);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	cout<<v.size();


	return 0;
}