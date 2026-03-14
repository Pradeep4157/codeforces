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
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    map<char, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]].push_back(i);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> &indexes = mp[s[i]];
        auto it = lower_bound(indexes.begin(), indexes.end(), i + l);
        if (it == indexes.end())
            continue;
        // there is something..
        int start = it - indexes.begin();
        auto it1 = upper_bound(indexes.begin(), indexes.end(), i + r);
        it1--;
        if (it1 == indexes.end())
            continue;
        int end = it1 - indexes.begin();
        res += max(0LL, end - start + 1);
    }
    cout << res << endl;
    return 0;
}
