// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int n;
//     int result = 0;
//     int base = 0;
//     cin >> n;
//     // 높이가 달라지는 경우...

//     for (int i = 0; i < n; i++)
//     {
//         int x, height = 0;
//         cin >> x >> height; // x는 안씀
//         // 높이가 높아지는경우.. 혹은 처음 시작하는 경우....
//         if (base == 0)
//         {
//             base = height;
//             result++;
//         }

//         else if (base < height)
//         {
//             result++;
//         }
//         // 높이가 낮아지는 경우....
//         else if (base > height)
//         {
//             if (height != 0)
//             {
//                 base = height;
//                 result++;
//             }
//             else
//             {
//                 base = 0;
//             }
//         }
//     }

//     cout << result;

//     return 0;
// }

// //   * *
// //  ** **
// // ******
// // => 5개

// //  *
// // ** *
// // *****
// // => 4개

// // *
// // **
// // ***
// // ***
// // => 3

// // *
// // **
// // ***
// // ****
// // => 4개

// //  *
// // *** *
// // *****
// // => 4

// //   ** **
// //  ******
// // ********
// // => 4
// 6
// 1 1
// 2 2
// 3 3
// 5 2
// 6 3
// 8 1

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, result = 0, x, y;
    cin >> n;
    vector<int> v;
    for (int i = 0; i <= n; i++)
    {
        if (i != n)
        {

            cin >> x >> y;
        }
        else
        {
            y = 0;
        }

        while (!v.empty() && v.back() >= y)
        {
            if (v.back() != y)
            {
                result++;
            }
            v.pop_back();
        }
        v.push_back(y);
    }
    cout << result;

    return 0;
}