#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> mp;
        mp[s[0]]++;
        bool ok = false;
        for (int i = 1; i < n; i++)
        {
            if (mp.find(s[i]) != mp.end() && i < n - 1)
            {
                ok = 1;
                break;
            }
            mp[s[i]]++;
        }
        unordered_map<char, int> mp2;
        mp2[s[n - 1]]++;
        for (int i = n - 2; i >= 0; i--)
        {
            if (mp2.find(s[i]) != mp.end() && i != 0)
            {
                ok = 1;
                break;
            }
            mp[s[i]]++;
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
