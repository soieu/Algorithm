#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// {번호, 추천 받은 횟수} 이런 식으로 저장이 되어야하고
// 추천받은 회수는 증감이 가능해야함
// 사진틀에 걸린 순서대로 들어와야하고
// 중간에 있는것도 삭제할 수 있어야함
// 아니면 추천수 오름차순 -> 사진 걸린 순서대로 정렬되어서 가장 왼쪽에있는게 탈락하게 하던지
// 중간에 삭제 가능 -> 리스트
// 들어오거나 추천수 오를때마다 정렬 해서 왼쪽 탈락 -> 큐
// 매번 정렬을 해야하면 시간 복잡도가 많이 나올듯
// 링크드 리스트

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, thumbCount;
    list<pair<int, int>> frame;
    cin >> n >> thumbCount;
    for (int i = 0; i < thumbCount; i++)
    {
        int thumb;
        cin >> thumb;

        bool found = false;

        // 추천받은 학생의 사진이 사진틀에 게시되어있다면 개수 올리기
        for (auto &p : frame)
        {
            if (p.first == thumb)
            {
                p.second++; // 추천 횟수 증가
                found = true;
                break;
            }
        }
        // 사진틀이 3개 이상이고 추천 받은 학생의 사진이 사진틀에 게시되지 않았다면
        // 추천 받은 횟수가 가장 적은 학생의 사진 삭제
        // 추천 받은 횟수가 가장 적은 학생이 두개라면 먼저 들어온 거 삭제
        // 사진틀이 두 개 이하이면 추가
        if (!found)
        {
            // 새로운 사진 추가
            if (frame.size() >= n)
            {
                // 가장 추천 횟수가 적은 사진 삭제
                frame.remove(*min_element(frame.begin(), frame.end(),
                                          [](const pair<int, int> &a, const pair<int, int> &b)
                                          {
                                              return a.second < b.second;
                                          }));
            }
            frame.push_back({thumb, 1}); // 새 사진 추가
        }
    }
    vector<int> sortedNumbers;
    for (const auto &p : frame)
    {
        sortedNumbers.push_back(p.first);
    }
    sort(sortedNumbers.begin(), sortedNumbers.end());

    for (const auto &num : sortedNumbers)
    {
        cout << num << " ";
    }

    return 0;
}