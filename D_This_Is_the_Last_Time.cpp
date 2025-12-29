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
        int n, x;
        cin >> n >> x;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            int left, right, val;
            cin >> left >> right >> val;
            arr.push_back({left, val, right});
        }
        sort(arr.begin(), arr.end());
        set<int> st;
        st.insert(x);
        for (int i = 0; i < n; i++)
        {
            int left = arr[i][0];
            int right = arr[i][2];
            int val = arr[i][1];
            auto it = st.lower_bound(left);
            if (it == st.end())
            {
                continue;
            }
            int ele = *it;
            if (ele <= right)
            {
                st.insert(val);
            }
        }
        int res = x;
        for (auto a : st)
        {
            res = max(res, a);
        }
        cout << res << endl;
    }
    return 0;
}
