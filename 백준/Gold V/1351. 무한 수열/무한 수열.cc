#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long int ll;

map<ll, ll> m;
ll ultimit(ll p, ll q, ll cur)
{
    // Base case
    if (cur == 0)
        return 1;

    // Check if the result for 'cur' has already been computed
    if (m.count(cur))
    {
        return m[cur]; // Directly return the stored result
    }

    // Recursively compute the value if not already computed
    ll result = ultimit(p, q, cur / p) + ultimit(p, q, cur / q);
    m[cur] = result; // Store the computed result in the map before returning

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, p, q;
    cin >> n >> p >> q;

    ll result = ultimit(p, q, n);

    cout << result;

    return 0;
}