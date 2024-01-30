#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1);
    vector<int> answer(n+1, 0);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        queue<int> q;
        q.push(i);
        vector<int> visited(n+1, 0);
        visited[i] = 1;
        int count = 1;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int adj : graph[cur]) {
                if(!visited[adj]) {
                    visited[adj] = 1;
                    q.push(adj);
                    count++;
                }
            }
        }
        answer[i] = count;
    }

    int maxCount = *max_element(answer.begin() + 1, answer.end());
    vector<int> real_answer;

    for(int i = 1; i <= n; i++) {
        if(answer[i] == maxCount) {
            real_answer.push_back(i);
        }
    }

    for(int i = 0; i < real_answer.size(); i++) {
        cout << real_answer[i] << (i < real_answer.size() - 1 ? " " : "");
    }

    return 0;
}
