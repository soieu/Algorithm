#include <iostream>
#include <queue>
using namespace std;

int visited[100010] = {
    0,
};

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int dfs(int end)
{
    int start;
    int count = 0;

    while (true)
    {
        count = q.top().first;
        start = q.top().second;
        q.pop();
        // end랑 동일하면 종료
        if (start == end)
        {
            return count;
        }
        if (start != 0 && start * 2 < 100001 && visited[start * 2] == 0)
        {
            q.push({count, start * 2});
            visited[start * 2] = 1;
        }
        if (start + 1 < 100001 && visited[start + 1] == 0)
        {
            q.push({count + 1, start + 1});
            visited[start + 1] = 1;
        }
        if (start - 1 >= 0 && visited[start - 1] == 0)
        {
            q.push({count + 1, start - 1});
            visited[start - 1] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p1, p2;
    cin >> p1 >> p2;

    q.push({0, p1});
    visited[p1] = 1;
    cout << dfs(p2);

    return 0;
}