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
        int n, a, b;
        cin >> n >> a >> b;
        while (true)
        {
            if (n < a)
                break;
            n -= a;
            n += b;
        }
        cout << n << endl;
    }
    return 0;
}
