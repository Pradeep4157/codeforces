#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto a : s)
        mp[a]++;
    char res;
    for (auto a : mp)
    {
        if (a.second == 1)
        {
            res = a.first;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
