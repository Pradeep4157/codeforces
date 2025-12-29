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

        set<int> st;
        int res = 0;
        while (true)
        {
            if (st.count(a))
                break;
            st.insert(a);
            res = max(res, a);
            a += b;
            a %= n;
        }
        cout << res << endl;
    }
    return 0;
}
