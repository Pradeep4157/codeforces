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
        int y, r;
        cin >> y >> r;
        cout << min(n, (y / 2) + r) << endl;
    }
    return 0;
}
