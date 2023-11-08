#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define weight first
#define vertex second

int v, e, k;
const int INF = 0x7FFFFFFF;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        vector<pair<int, int>> adj[20005];
        int d[20001]; // 최단 거리 테이블
        cin >> v >> e >> k;
        fill(d, d + v + 1, INF); // 최단거리 테이블 우선 다 inf로 초기화

        // 간선 값 넣기
        while (e--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[v].push_back({w, u});
        }

        // 우선순위큐     자료형             컨테이너                    cmp
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // 시작 -> 시작 거리는 0으로
        d[k] = 0;

        // 우선순위 큐에 (특정 정점까지의 거리,특정 정점) 삽입
        pq.push({d[k], k});
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop(); // {비용, 정점 번호}

            // 거리가 d에 있는 값과 다를 경우 넘어감 (현재 정점까지의 이동거리가 현재 알고있는 최소 루트로 온 게 아닌 경우 넘어감 -> d에 절대로 적히지 못하는 경로이기 때문)
            if (d[cur.vertex] != cur.weight)
                continue;

            // nxt에 cur과 연결된 {비용,정점} 를 넣는 것을 반복
            for (auto nxt : adj[cur.vertex])
            {
                // 다음 정점의 현재 최소 거리보다 지금 정점까지의 최소거리 + 지금 정점에서 다음 정점까지의 비용이 크면 그냥 넘어감
                if (d[nxt.vertex] <= d[cur.vertex] + nxt.weight)
                    continue;
                // 새로운 최소 거리를 찾는 경우
                // d[nxt.vertex]을 갱신하고 우선순위 큐에 (거리, nxt.vertex)를 추가
                d[nxt.vertex] = d[cur.vertex] + nxt.weight;
                pq.push({d[nxt.vertex], nxt.vertex});
            }
        }

        int max_result = 0;
        int result = 0;
        for (int i = 1; i <= v; i++)
        {
            if (d[i] != INF)
            {
                max_result = max(max_result, d[i]);
                result++;
            }
        }
        cout << result << " " << max_result << "\n";
    }
}