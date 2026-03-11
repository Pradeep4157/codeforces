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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    bool ok = 1;
    if (n > m)
        ok = false;
    for (int i = 0; i < n; i++)
    {
        if (i >= m)
            break;
        if (s[i] != t[i])
        {
            ok = false;
            break;
        }
    }
    cout << ((ok) ? "Yes" : "No") << endl;
    return 0;
}
