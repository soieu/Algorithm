#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 0x7FFFFFFF;
int d[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x;
    int max_time = 0;
    vector<pair<int, int>> graph[1001];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++)
    {
        int start, end, time;
        cin >> start >> end >> time;
        graph[start].push_back({time, end});
    }

    // 최단 시간 테이블 초기화
    fill(&d[0][0], &d[1000][1001], INF);
    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
    }

    // 최단 시간 테이블 만들고만들고~
    for (int i = 1; i <= n; i++)
    {
        pq.push({d[i][i], i});

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            if (d[i][cur.second] != cur.first)
                continue;

            for (auto next : graph[cur.second])
            {
                if (d[i][next.second] <= d[i][cur.second] + next.first)
                    continue;
                d[i][next.second] = d[i][cur.second] + next.first;
                pq.push({d[i][next.second], next.second});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i][x] + d[x][i] > max_time)
        {
            max_time = d[i][x] + d[x][i];
        }
    }
    cout << max_time;

    return 0;
}