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
        int n, mod;
        cin >> n >> mod;
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            arr[i] %= mod;
        for (int i = 0; i < n; i++)
            b[i] %= mod;
        int res = 0;
        multiset<int> st;
        for (auto a : b)
            st.insert(a);
        for (int i = 0; i < n; i++)
        {
            auto it = st.lower_bound(mod - arr[i]);
            if (it != st.end())
            {
                res += (arr[i] + *it) % mod;
                st.erase(it);
            }
            else
            {
                auto it1 = st.begin();
                res += (arr[i] + *it1) % mod;
                st.erase(it1);
            }
        }
        cout << res << endl;
    }
    return 0;
}
