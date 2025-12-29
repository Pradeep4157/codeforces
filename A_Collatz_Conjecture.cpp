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
        int k, x;
        cin >> k >> x;
        while (k)
        {
            k--;
            x *= 2;
        }
        cout << x << endl;
    }
    return 0;
}
