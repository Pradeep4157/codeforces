#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if n is odd , 0

    else 2,4,6,8,10,12,... till cow>=4

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
        int res = 0;
        for (int i = 0; i <= n; i += 2)
        {
            int rem = n - i;
            if (rem % 4 == 0)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}
