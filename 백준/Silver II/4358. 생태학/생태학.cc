#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> trees;
    float num = 0;

    string tree = "";
    while (getline(cin, tree))
    {
        num++;
        
        if (trees.find(tree) != trees.end())
        {
            trees[tree] += 1;
        }
        else
        {
            trees.insert({tree, 1});
        }
    }

    cout << fixed;
    cout.precision(4);

    for (auto it = trees.begin(); it != trees.end(); it++)
    {
        cout << it->first << " " << float(it->second) * 100 / num << "\n";
    }

    return 0;
}