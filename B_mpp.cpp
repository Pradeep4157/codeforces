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
    {
        mp[a]++;
    }
    int maxi = 0;
    for (auto a : mp)
    {
        maxi = max(a.second, maxi);
    }
    string res;
    for (auto a : s)
    {
        if (mp[a] != maxi)
            res += a;
    }
    cout << res << endl;
    return 0;
}
