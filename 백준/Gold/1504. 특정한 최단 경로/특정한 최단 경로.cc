#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 0x7fffffff
#define COST first
#define VERTEX second
using namespace std;

vector<pair<int, int>> v[801]; // v[정점] = {값, 도착점} => 쌍으로 만들어야함
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int arrStart[801];
int arrMustOne[801];
int arrMustTwo[801];
int n, e;

void dijkstra(int arr[], int start)
{
    pq.push({arr[start], start});
    while (!pq.empty())
    {
        // 1. 우선순위 큐의 부모 노드를 참조하고, 없앤다
        auto cur = pq.top();
        pq.pop();

        // 2. 최소비용 테이블에 저장된 값과 우선순위 큐에서 꺼낸 비용이 동일하면 정상 작동
        if (arr[cur.VERTEX] != cur.COST)
            continue;
        // 3. 우선순위 큐에 현재 점과 연결된 점들 & 그들의 최소 비용 넣기
        for (auto nxt : v[cur.VERTEX])
        {
            if (arr[nxt.VERTEX] > arr[cur.VERTEX] + nxt.COST)
            {
                arr[nxt.VERTEX] = arr[cur.VERTEX] + nxt.COST;
                pq.push({arr[nxt.VERTEX], nxt.VERTEX});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int mustOne, mustTwo;
    cin >> n >> e;

    // 최단거리 테이블 값 초기화
    fill(arrStart, arrStart + n + 1, INF);
    fill(arrMustOne, arrMustOne + n + 1, INF);
    fill(arrMustTwo, arrMustTwo + n + 1, INF);
    // 양방향으로 이동 가능
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    cin >> mustOne >> mustTwo;

    // 시작점 초기화
    arrStart[1] = 0;
    arrMustOne[mustOne] = 0;
    arrMustTwo[mustTwo] = 0;

    dijkstra(arrStart, 1);
    dijkstra(arrMustOne, mustOne);
    dijkstra(arrMustTwo, mustTwo);

    // 둘 다 inf가 하나 이상 있으면
    if ((arrStart[mustOne] == INF || arrMustOne[mustTwo] == INF || arrMustTwo[n] == INF) && (arrStart[mustTwo] == INF || arrMustTwo[mustOne] == INF || arrMustOne[n] == INF))
        cout << "-1";
    else
        cout << min(arrStart[mustOne] + arrMustOne[mustTwo] + arrMustTwo[n], arrStart[mustTwo] + arrMustTwo[mustOne] + arrMustOne[n]);

    return 0;
}