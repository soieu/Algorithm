#include <iostream>
#include <vector>
using namespace std;

vector<string> words; // 단어 저장
int maxCount = 0;     // 최대 개수

int n, k;
// a, b, c ...

void backtracking(int index, bool alphabet[], int selectedCount)
{
    if (selectedCount == k)
    {
        int count = 0;
        for (const auto &word : words)
        {
            bool canRead = true;
            for (char ch : word)
            {
                if (!alphabet[ch - 'a'])
                {
                    canRead = false;
                    break;
                }
            }
            if (canRead)
                count++;
        }
        maxCount = max(maxCount, count);
        return;
    }

    for (int i = index; i < 26; i++)
    {
        if (!alphabet[i])
        {
            alphabet[i] = true;
            backtracking(i + 1, alphabet, selectedCount + 1);
            alphabet[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool alphabet[26] = {false};
    // 'a', 'n', 't', 'i', 'c'는 항상 포함되어야 함
    alphabet['a' - 'a'] = alphabet['n' - 'a'] = alphabet['t' - 'a'] = alphabet['i' - 'a'] = alphabet['c' - 'a'] = true;

    cin >> n >> k;
    if (k < 5)
    { // 최소 5개 알파벳 필요
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        words.push_back(temp.substr(4, temp.size() - 8)); // 앞뒤 고정 문자 제거
    }

    backtracking(0, alphabet, 5); // 'a', 'n', 't', 'i', 'c'를 포함하여 시작

    cout << maxCount;

    return 0;
}
