#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<long long, long long>> villages(n);
    long long total_population = 0;

    for (int i = 0; i < n; ++i) {
        cin >> villages[i].first >> villages[i].second;
        total_population += villages[i].second;
    }

    sort(villages.begin(), villages.end());

    long long half_population = (total_population + 1) / 2;
    long long cumulative_population = 0;
    long long position = 0;

    for (const auto& village : villages) {
        cumulative_population += village.second;
        if (cumulative_population >= half_population) {
            position = village.first;
            break;
        }
    }

    cout << position << endl;

    return 0;
}