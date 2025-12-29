#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int curr = 0;
        int res = 0;
        int ans;
        while (true)
        {
            curr = (curr * 2) + 1;
            res += 2;
            if (curr >= x)
                break;
        }
        res++;
        cout << res << endl;
    }
    return 0;
}
