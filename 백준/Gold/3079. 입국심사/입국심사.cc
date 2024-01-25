#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// // 입국심사대의 시간
// array<int,100001> T = {0,};
// array<int,100001> TTime = {0,};


// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     // 입국심사대는 n개, 사람 수는 m 개
//     int n, m;

//     cin>>n>>m;

//     for(int i = 0; i < n; i++)
//     {
//         cin>>T[i];
//         TTime[i] = T[i];
//     }

//     for(int i = 0; i < m; i++)
//     {
//         int minIndex = min_element(T.begin(), T.begin() + n) - T.begin();
//         T[minIndex] += TTime[minIndex];
//     }

//     cout << *min_element(T.begin(), T.begin() + n);


//     return 0;
// }

typedef unsigned long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m, ans = 0;
    vector<ll> v;

    cin>>n>>m;

    for(ll i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    // sort(v.begin(), v.end());

    ll left = 1;
    ll right = *max_element(v.begin(), v.end()) * m;

    while(left <= right)
    {
        ll mid = (left + right) / 2;

        ll capacity = 0;

        for (int i = 0; i < n; i++){
            capacity += mid / v[i]; 
        }
        
        if( capacity >= m)
        {
            if(ans > mid || ans == 0)
            {
                ans = mid;
            }
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }

    }
    cout << ans;
    return 0;
}
// longlong :           1000000000000000000
// unsigned longlong :  1000000000000000000
