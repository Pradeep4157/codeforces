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
        int n, m, d;
        cin >> n >> m >> d;
        int best = d / m;
        best++;

        int res = n / best;
        int rem = n - (res * best);
        if (rem > 0)
            res++;
        cout << res << endl;
    }
    return 0;
}
