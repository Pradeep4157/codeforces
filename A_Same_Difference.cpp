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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        char last = s[n - 1];
        int res = 0;
        for (auto a : s)
            if (a != last)
                res++;
        cout << res << endl;
    }
    return 0;
}
