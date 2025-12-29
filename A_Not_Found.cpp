#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto a : s)
    {
        mp[a]++;
    }
    char res;
    for (int i = 0; i < 26; i++)
    {
        char curr = i + 'a';
        if (mp.find(curr) == mp.end())
        {
            res = curr;
            break;
        }
    }
    cout << res << endl;

    return 0;
}
