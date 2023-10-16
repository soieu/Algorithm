#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> character;
int L, C;
bool isUsed[16];
char makeC[16];

void bt(int index, int cVowel, int cConsonant)
{
    if (index == L && cVowel >= 1 && cConsonant >= 2)
    {
        for (int i = 0; i < L; i++)
        {
            cout << makeC[i];
        }
        cout << "\n";
        return;
    }
    else if (index == L)
    {
        return;
    }
    for (int i = 0; i < C; i++)
    {
        if (!isUsed[i] && (index == 0 || makeC[index - 1] < character[i]))
        {
            makeC[index] = character[i];
            isUsed[i] = 1;
            int vorc = 0;
            if (character[i] == 'a' || character[i] == 'e' || character[i] == 'i' || character[i] == 'o' || character[i] == 'u')
            {
                vorc = 1;
                cVowel++;
            }
            else
            {
                vorc = 2;
                cConsonant++;
            }
            bt(index + 1, cVowel, cConsonant);
            if (vorc == 1)
                cVowel--;
            else
                cConsonant--;
            isUsed[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        char temp;
        cin >> temp;
        character.push_back(temp);
    }
    sort(character.begin(), character.end());

    bt(0, 0, 0);

    return 0;
}