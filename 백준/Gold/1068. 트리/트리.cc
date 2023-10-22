#include <iostream>
#include <vector>
using namespace std;

int visited[55];
vector<int> v[55];
int deleteNode;

int DFS(int curr)
{
    int ret = 1;
    int child = 0;
    for (auto ch : v[curr])
    {
        if (ch == deleteNode)
            continue;
        child += DFS(ch);
    }
    if (child)
        return child;

    else
        return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int root;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == -1)
            root = i;
        else
            v[a].push_back(i);
    }
    cin >> deleteNode;

    if (root != deleteNode)
        cout << DFS(root) << '\n';
    else
        cout << 0 << '\n';

    return 0;
}