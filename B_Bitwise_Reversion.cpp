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
        int x, y, z;
        cin >> x >> y >> z;
        int common = x & y & z;
        x ^= common;
        y ^= common;
        z ^= common;
        bool ok = 1;
        if ((x & y) > 0 || (y & z) > 0 || (x & z) > 0)
            ok = false;
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
