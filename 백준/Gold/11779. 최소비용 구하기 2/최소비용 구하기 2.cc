#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define COST first
#define VERTEX second

using namespace std;
int INF = 0x7fffffff;
int d[1001];
int track[1001];
int print_track[1001];

vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // n : 도시의 개수 , m : 버스의 개수
    int n, m;
    int a_start, a_end;
    cin >> n >> m;
    fill(d, d + n + 1, INF);
    fill(track, track + n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        adj[start].push_back({cost, end});
    }
    cin >> a_start >> a_end;

    // 시작점은 초기화
    d[a_start] = 0;
    track[a_start] = a_start;

    // pq에 {비용, 점} 추가
    pq.push({d[a_start], a_start});
    while (!pq.empty())
    {
        // 1. 우선순위 큐의 부모 노드를 참조하고, 없앤다
        auto cur = pq.top();
        pq.pop();

        // 2. 최소비용 테이블에 저장된 값과 우선순위 큐에서 꺼낸 비용이 동일하면 정상 작동
        if (d[cur.VERTEX] != cur.COST)
            continue;
        // 3. 우선순위 큐에 현재 점과 연결된 점들 & 그들의 최소 비용 넣기
        for (auto nxt : adj[cur.VERTEX])
        {
            if (d[nxt.VERTEX] > d[cur.VERTEX] + nxt.COST)
            {
                d[nxt.VERTEX] = d[cur.VERTEX] + nxt.COST;
                track[nxt.VERTEX] = cur.VERTEX;
                pq.push({d[nxt.VERTEX], nxt.VERTEX});
            }
        }
    }
    cout << d[a_end] << "\n";
    int cur = a_end;
    int i = 0;
    while (cur != a_start)
    {
        print_track[i] = cur;
        cur = track[cur];
        i++;
    }
    print_track[i] = a_start;
    cout << i + 1 << "\n";
    i++;
    while (i--)
    {
        cout << print_track[i] << " ";
    }

    return 0;
}