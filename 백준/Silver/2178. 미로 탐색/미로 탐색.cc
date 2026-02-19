#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 최단 거리 찾기 = BFS
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, num = 2;
    int n_loc = 0, m_loc = 0;
    /*
        n0m0 n0m1 n0m2
        n1m0 n1m1 n1m2
        n2m0 n2m1 n2m2
    */

    cin>>n>>m;

    int map[n][m];
    int track[n][m] = {0,};
    int visited[n][m] = {0,};
    int n_dir[4] = {-1, 1, 0, 0};   // 상하좌우 x축 방향
    int m_dir[4] = {0, 0, -1, 1};   // 상하좌우 y축 방향
    track[0][0] = 1;

    queue<pair<int,int> > q;        // 탐색 좌표 저장용 queue


    for(int i = 0; i < n; i++)
    {
        string row;
        cin >> row;

        //맵 만들기
        for(int j = 0; j<m; j++)
        {
            map[i][j] = row[j]-'0';
        }
    }

    q.push(make_pair(n_loc,m_loc));
    while(!q.empty())
    {
        visited[n_loc][m_loc] = 1; 
        //처음 들어갔을 때 : queue에 한 쌍 들어가있음
        for(int i = 0; i < 4; i++)
        {
            if(map[n_loc+n_dir[i]][m_loc+m_dir[i]] != 0 && visited[n_loc+n_dir[i]][m_loc+m_dir[i]] != 1 && (n_loc+n_dir[i] >= 0 && n_loc+n_dir[i] <n ) && (m_loc+m_dir[i] >= 0 && m_loc+m_dir[i] < m))//이동하려는 곳의 map이 0이거나, 이미 방문했거나, map 밖이면 실행 X
            {
                n_loc += n_dir[i];
                m_loc += m_dir[i];
                q.push(make_pair(n_loc,m_loc));
                track[n_loc][m_loc] = track[n_loc-n_dir[i]][m_loc-m_dir[i]] + 1;
                visited[n_loc][m_loc] = 1; 
                //바꾼 위치 우선 초기화
                n_loc -= n_dir[i];
                m_loc -= m_dir[i];
            }
        }
        num++;
        q.pop();
        if(!q.empty())
        {
            n_loc = q.front().first;
            m_loc = q.front().second;
        }
    }
    cout<<track[n-1][m-1];

    return 0;
}