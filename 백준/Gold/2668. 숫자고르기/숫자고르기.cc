#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> v;
set<int> s;
int n;

/**
 * 시작 인덱스를 인수로 받고
 * 아예 종료되는 경우 (s의 length가 n과 동일한 경우 1 반환. 일반적인 경우 0 반환)
 */
void dfs(int start, int cur, int visited[], vector<int> temp)
{
    // 방문 안한 경우
    if (visited[v[cur]] == 0)
    {
        visited[v[cur]] = 1;
        temp.push_back(cur);
        dfs(start, v[cur], visited, temp);
    }
    // 시작 지점 방문한 경우 = dfs 종료, set 설정
    else if (v[cur] == start)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            s.insert(temp.back());
            temp.pop_back();
        }
        return;
    }

    // 시작 지점이 아닌 이미 방문한 곳을 방문한 경우 = dfs 종료
    else if (visited[v[cur]] == 1)
    {
        temp.clear();
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int temp;

        cin >> temp;

        v.push_back(temp);
    }
    /*
        [1 3 4 2]가 있을 때
        => [1] -> 1 끝.... => set에 1 넣어 !! {1}
        => [2] -> 3 -> [3] -> 4 -> [4] -> 2 -> [2] => set에 3, 4, 2 넣어 !! { 3, 4, 2, 1} => 길이가 n이랑 똑같아지면 종료
    */
    for (int i = 1; i <= n; i++)
    {
        if (s.size() == n)
            break;
        int visited[101] = {
            0,
        };
        vector<int> temp;
        visited[i] = 1;
        temp.push_back(i);
        dfs(i, v[i], visited, temp);
    }

    set<int>::iterator iter;
    cout << s.size() << "\n";
    for (iter = s.begin(); iter != s.end(); iter++)
    {
        cout << *iter << "\n";
    }
    return 0;
}