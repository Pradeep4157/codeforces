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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        if (i <= m)
            cout << "OK" << endl;
        else
            cout << "Too Many Requests" << endl;
    }
    return 0;
}
