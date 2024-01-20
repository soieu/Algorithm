#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll lecture_length[100001] = {0,};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m, total, left = -1, right, mid;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> lecture_length[i];

        // 모든 강의의 총 길이 구하기
        total += lecture_length[i];

        // 가장 긴 한 강의의 길이를 left값으로 설정
        left = max(left, lecture_length[i]);
    }

    right = total;

    while(left <= right)
    {
        ll count = 0, temp_sum = 0;
        mid = (left+right) / 2;

        // 블루레이에 분배하기
        for(int i = 0; i < n; i++)
        {
            if(temp_sum + lecture_length[i] > mid)
            {
                temp_sum = 0;
                count += 1;
            }
            temp_sum += lecture_length[i];
        }
        if(temp_sum != 0)
        {
            count += 1;
        }

        // m보다 작거나 같은 경우 
        if(count <= m)
        {
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }


    }
    cout<<left;

    return 0;
}