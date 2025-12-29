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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int firstmaxi = max(a, b);
        int firstmini = min(a, b);
        if (firstmaxi > ((2 * firstmini) + 2))
        {
            cout << "NO" << endl;
            continue;
        }
        c -= a;
        d -= b;
        int maxi = max(c, d);
        int mini = min(c, d);
        if (maxi > ((2 * mini) + 2))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
