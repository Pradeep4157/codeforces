#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    max - min should be minimized..

    we can multiply ai by 2..


    lets guess...

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
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            st.insert(ele);
        }
        int ops = 1e5;
        int res = *st.rbegin() - *st.begin();
        while (ops--)
        {
            int first = *st.begin();
            if (first > (LLONG_MAX) / 2LL)
                break;
            st.erase(st.begin());
            st.insert(first * 2);
            int curr = *st.rbegin() - *st.begin();
            res = min(res, curr);
        }
        cout << res << endl;
    }
    return 0;
}
