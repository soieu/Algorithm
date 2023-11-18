#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> taller[502];
vector<int> smaller[502];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        taller[a].push_back(b);
        smaller[b].push_back(a);
    }
    /*
    taller
    1 : 5
    2 :
    3 : 4
    4 : 2, 6
    5 : 2, 4
    smaller
    1 :
    2 : 5
    3 :
    4 : 3, 5
    5 : 1
    6 : 4
*/
    for (int i = 1; i <= n; i++)
    {
        // taller 추가
        int visited[502] = {
            0,
        };
        visited[i] = 1;
        // 중복해서 넣어지는거 방지해서 이미 있는건 넣어놓음
        for (int j = 0; j < taller[i].size(); j++)
        {
            q.push(taller[i][j]);
            visited[taller[i][j]] = 1;
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < taller[cur].size(); j++)
            {
                int next = taller[cur][j];
                if (visited[next] == 1)
                {
                    continue;
                }
                q.push(next);
                visited[next] = 1;
                taller[i].push_back(next);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // smaller 추가
        q.push(i);
        int visited[502] = {
            0,
        };
        visited[i] = 1;
        // 중복해서 넣어지는거 방지해서 이미 있는건 넣어놓음
        for (int j = 0; j < smaller[i].size(); j++)
        {
            q.push(smaller[i][j]);
            visited[smaller[i][j]] = 1;
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < smaller[cur].size(); j++)
            {
                int next = smaller[cur][j];
                if (visited[next] == 1)
                {
                    continue;
                }
                q.push(next);
                visited[next] = 1;
                smaller[i].push_back(next);
            }
        }
    }

    /*
    taller
    1 : 5, 4, 2, 6
    2 :
    3 : 4, 6, 2
    4 : 2, 6
    5 : 2, 4, 6
    smaller
    1 :
    2 : 5, 4, 3, 1
    3 :
    4 : 3, 5, 1
    5 : 1
    6 : 4, 3, 5, 1
    */

    // 개수 세기
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (taller[i].size() + smaller[i].size() == n - 1)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}