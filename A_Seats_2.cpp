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
    int t = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        n = (n + 1) / 2;
        cout << ((n >= m) ? "Yes" : "No") << endl;
    }
    return 0;
}
