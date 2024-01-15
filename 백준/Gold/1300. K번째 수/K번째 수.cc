#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long n;
	long long k;

	cin>>n>>k;

	// 최소값을 0으로, 최대 값을 n*n으로 지정하고 이분탐색
	long long min_val = 1;
	long long max_val = min((long long)1000000000,n*n);
	int count;

	// 이분탐색
	while(min_val <= max_val)
	{
		long long mid = (min_val+max_val) / 2;
		count = 0;
		// mid 보다 작은 수의 개수 구하기
		for(long long i = 1; i <= n; i++)
		{
			// ex) [i = 2 & mid = 4] => 2, 4, 6, 8, 10 => 2개만 나와야함. 4까지 세야함
			count += min(mid / i, n);
		}
		if(count >= k)
		{
			max_val = mid - 1;
		}
		else
		{
			min_val = mid + 1;
		}
	}
	cout<<min_val;


	return 0;
}