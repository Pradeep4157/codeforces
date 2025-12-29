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
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int res = 1;
        for (int len = 1; len <= n; len++)
        {
            int curr = 0;
            for (auto a : mp)
            {
                if (a.second >= len)
                    curr += len;
            }
            res = max(res, curr);
        }
        cout << res << endl;
    }
    return 0;
}
