// #include <iostream>
// #include <list>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     list<char> L;

//     string temp;
//     cin >> temp;
//     string bomb;
//     cin >> bomb;
//     for (int i = 0; i < temp.size(); i++)
//     {
//         L.push_back(temp[i]);
//     }
//     while (true)
//     {
//         int flag = 0; // flag가 0인 경우 폭탄 문자열이 없음. flag가 1인 경우 폭탄 문자열 발생
//         for (auto i = L.begin(); i != L.end(); i++)
//         {
//             auto cur = i;

//             // cout << "i : " << *i << "\n";
//             if (*i == bomb[0])
//             {
//                 // cout << "cur: " << *cur << "\n";
//                 // 처음 문자열부터, bomb의 마지막 문자열 까지 동일한지 확인
//                 auto iter = i;
//                 iter++;
//                 for (int j = 1; j < bomb.size(); j++)
//                 {
//                     // cout << "iter : " << *iter << "\n";

//                     if (*iter != bomb[j])
//                     {
//                         break;
//                     }
//                     if (j == bomb.size() - 1)
//                     {
//                         flag = 1;
//                         for (int k = 0; k < bomb.size(); k++)
//                         {
//                             // cout << "cur: " << *cur << "\n";
//                             cur = L.erase(cur);
//                         }
//                     }
//                     iter++;
//                 }
//             }
//             if (flag == 1)
//             {
//                 break;
//             }
//         }
//         if (flag == 0)
//         {
//             break;
//         }
//     }
//     if (!L.empty())
//     {
//         for (auto i = L.begin(); i != L.end(); i++)
//         {
//             cout << *i;
//         }
//     }
//     else
//     {
//         cout << "FRULA";
//     }

//     return 0;
// }
#include <iostream>
#include <stack>
using namespace std;

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;      // 전체 문자열 변수
    string b;      // 폭발 문자열 변수
    string t = ""; // 임시 문자열
    cin >> a >> b;
    int a_len = a.length(); // 전체 문자열 길이
    int b_len = b.length(); // 폭발 문자열 길이
    for (int i = 0; i < a.length(); i++)
    {
        t += a[i]; // 문자 추가
        if (t.length() >= b_len)
        {                     // 임시 문자 길이가 폭발 문자열 보다 크거나 같을 때
            bool flag = true; // 폭발 문자열 있는지 확인하는 flag
            for (int j = 0; j < b_len; j++)
            {
                if (t[t.length() - b_len + j] != b[j])
                {
                    flag = false;
                    break;
                } // t뒤에서 폭발 문자열 길이만큼 비교
            }

            if (flag) // 폭발 문자열일 경우 삭제
                t.erase(t.end() - b_len, t.end());
        }
    }
    if (t.empty()) // 남아 있는 문자열이 없는 경우
        cout << "FRULA" << '\n';
    else
        cout << t << '\n';
    return 0;
}