#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int city_count = 0;
    int travel_city_count = 0;

    cin >> city_count >> travel_city_count;

    // 중복이 들어올 수 있으니 set으로
    set<int> graph[city_count + 2];

    // 연결되어있는거 입력 받고
    for (int from = 1; from <= city_count; from++)
    {
        for (int to = 1; to <= city_count; to++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                graph[from].insert(to);
                graph[to].insert(from);
            }
        }
    }
    set<int> travel_city_set;
    for (int travel_city = 0; travel_city < travel_city_count; travel_city++)
    {
        int temp;
        cin >> temp;
        travel_city_set.insert(temp);
    }
    vector<int> travel_city_array;
    set<int>::iterator iter;
    for (iter = travel_city_set.begin(); iter != travel_city_set.end(); iter++)
    {
        travel_city_array.push_back(*iter);
    }

    // 연결되어있는지 bfs나 dfs로 확인
    int visited[202] = {
        0,
    };

    queue<int> q;
    q.push(travel_city_array[0]);
    visited[travel_city_array[0]] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (iter = graph[cur].begin(); iter != graph[cur].end(); iter++)
        {
            if (visited[*iter] == 0)
            {
                visited[*iter] = 1;
                q.push(*iter);
            }
        }
    }

    for (int travel_city = 0; travel_city < travel_city_array.size(); travel_city++)
    {
        if (visited[travel_city_array[travel_city]] == 0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}