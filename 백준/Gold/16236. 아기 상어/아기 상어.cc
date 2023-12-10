#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
vector<pair<int, int>> feeds[7]; // (x, y)
int map[23][23] = {
    0,
};
int sec = 0;
int baby_shark_size = 2;
int exp = 0;
int n = 0;
int cur_x = -1;
int cur_y = -1;
int target_size = -1;
int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};

void print_map()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == cur_y && cur_x == j)
                cout << "# ";
            else if (map[i][j] == 0)
                cout << ". ";
            else
                cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n"
         << baby_shark_size << " " << exp << " "
         << sec << "\n";
}

void eat_fish()
{
    // map reset
    map[cur_y][cur_x] = 0;

    // feeds reset
    auto removeIter = remove_if(feeds[target_size].begin(), feeds[target_size].end(),
                                [=](const auto &element)
                                {
                                    return element.first == cur_x && element.second == cur_y;
                                });

    feeds[target_size].erase(removeIter, feeds[target_size].end());

    // grow up
    if (++exp == baby_shark_size)
    {
        baby_shark_size++;
        exp = 0;
    }

    // print_map();
}

void set_map()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                cur_x = j;
                cur_y = i;
                map[i][j] = 0;
            }
            else if (map[i][j] != 0)
            {
                feeds[map[i][j]].push_back({j, i});
            }
        }
    }
}

// bfs,
void find_feed()
{
    while (1)
    {
        int min_sec = 0x7fffffff;
        int next_x = 0x7fffffff;
        int next_y = 0x7fffffff;
        for (int i = 1; i < (baby_shark_size > 7 ? 7 : baby_shark_size); i++)
        {
            for (int j = 0; j < feeds[i].size(); j++)
            {
                auto can_eat_fish = feeds[i][j];
                queue<tuple<int, int, int>> q; // (x, y, sec)
                int visited[22][22] = {
                    0,
                };
                q.push({cur_x, cur_y, 0});

                while (!q.empty())
                {
                    int temp_x = get<0>(q.front());
                    int temp_y = get<1>(q.front());
                    int temp_sec = get<2>(q.front());
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int temp_next_x = temp_x + dir_x[k];
                        int temp_next_y = temp_y + dir_y[k];

                        // 도착한 경우
                        if (temp_next_x == can_eat_fish.first && temp_next_y == can_eat_fish.second)
                        {
                            ++temp_sec;
                            if (min_sec == temp_sec)
                            {
                                if (next_y == temp_next_y)
                                {
                                    if (next_x > temp_next_x)
                                    {
                                        min_sec = temp_sec;
                                        next_y = temp_next_y;
                                        next_x = temp_next_x;
                                        target_size = i;
                                    }
                                }
                                else if (next_y > temp_next_y)
                                {

                                    min_sec = temp_sec;
                                    next_y = temp_next_y;
                                    next_x = temp_next_x;
                                    target_size = i;
                                }
                            }
                            // 최초의 경우 무조건 여기 걸려서 min_sec 등등 초기화
                            else if (min_sec > temp_sec)
                            {
                                min_sec = temp_sec;
                                next_x = temp_next_x;
                                next_y = temp_next_y;
                                target_size = i;
                            }
                            while (!q.empty())
                            {
                                q.pop();
                            }
                            break;
                        }
                        if (temp_next_x < 0 || temp_next_y < 0 || temp_next_x >= n || temp_next_y >= n)
                        {
                            continue;
                        }
                        if (map[temp_next_y][temp_next_x] > baby_shark_size)
                        {
                            continue;
                        }
                        if (visited[temp_next_y][temp_next_x] == 1)
                        {
                            continue;
                        }
                        q.push({temp_next_x, temp_next_y, temp_sec + 1});
                        visited[temp_next_y][temp_next_x] = 1;
                    }
                }
            }
        }
        if (min_sec != 0x7fffffff && cur_x != 0x7fffffff && cur_y != 0x7fffffff)
        {
            cur_x = next_x;
            cur_y = next_y;
            sec += min_sec;
            eat_fish();
        }
        else
        {
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    set_map();

    find_feed();

    cout << sec;

    return 0;
}