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
    int a, b;
    cin >> a >> b;
    if (a >= b)
    {
        int diff = a - b;
        int res = 1;
        for (int i = 0; i < diff; i++)
        {
            res *= 32LL;
        }
        cout << res << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}
