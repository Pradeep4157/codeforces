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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> dp(n);
        dp[0] = 1;
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                dp[i + 1] = dp[i] + i + 1 + 1;
            }
            else
                dp[i + 1] = dp[i] + 1;
            res += dp[i];
        }

        res += dp[n - 1];
        cout << res << endl;
    }
    return 0;
}
