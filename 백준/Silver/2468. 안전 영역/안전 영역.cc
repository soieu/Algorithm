#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int map[101][101] = {0,};
queue<pair<int,int>> q;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	int top = 1;
	cin>>n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>map[i][j];
			top = max(top, map[i][j]);
		}
	}

	int max_count = 1;
	// 왼쪽 위부터 오른쪽 아래까지 탐색
	for(int rain = 1; rain < top; rain++)
	{
		int visited[101][101] = {0,};
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{

				// 물에 안잠기는 경우 탐색
				if(map[i][j] > rain && visited[i][j] ==0)
				{
					q.push({i,j});
					visited[i][j] = 1;
					count++;
					while(!q.empty())
					{

						int q_i= q.front().first;
						int q_j = q.front().second;
						q.pop();
						for(int k = 0; k < 4; k++)
						{
							if(q_i+dx[k] < 0 || q_j + dy[k] < 0 || q_i+dx[k] >= n || q_j + dy[k] >= n) continue;
							if(map[q_i+dx[k]][q_j+dy[k]] <= rain) continue;
							if(visited[q_i+dx[k]][q_j+dy[k]] == 1) continue;
							q.push({q_i+dx[k], q_j+dy[k]});
							visited[q_i+dx[k]][q_j+dy[k]] = 1;
						}
					}
				}
			}
		}
		max_count = max(count, max_count);
	}



	cout<<max_count;



	return 0;
}