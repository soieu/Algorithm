#include <iostream>
#include <vector>
using namespace std;

bool visited[2000];
int answer = false;
void dfs(int len, int cur, vector<vector<int>> &v)
{
    if (len == 4)
    {
        answer = true;
        return;
    }
    for (int i = 0; i < v[cur].size(); i++)
    {
        int nxt = v[cur][i];
        if (!visited[nxt])
        {
            visited[nxt] = true;
            dfs(len + 1, nxt, v);
            visited[nxt] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        dfs(0, i, v);
        visited[i] = false;
        if (answer)
            break;
    }
    cout << answer;

    return 0;
}