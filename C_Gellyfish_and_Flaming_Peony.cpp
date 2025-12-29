#include <bits/stdc++.h>
#define int int64_t
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        // n^2 method will work
        // if she wants to make all elements equal then it would be gcd(all elements)
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        sort(arr.begin(), arr.end());
        int gcd = arr[0];
        for (int i = 1; i < n; i++)
            gcd = __gcd(arr[i], gcd);
        int finalgcd = gcd;
        // now i need to find the element that i would first decrease to final_gcd
        // 6 10 15-> {3,2},{5,2},{5,3}
        for (int i = 0; i < n; i++)
        {
            arr[i] /= finalgcd;
        }
        if (arr[0] == 1)
        {
            int res = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] != 1)
                    res++;
            }
            cout << res << endl;
            continue;
        }
        int res = LLONG_MAX;
        // min steps required to reduce a number  to 1
        int maxi = arr[n - 1];
        // 6, 10,15
        vector<int> dp(arr[n - 1] + 1, -1);
        for (int i = 0; i < n; i++)
        {
            dp[arr[i]] = 0;
        }
        for (int i = maxi; i >= 1; i--)
        {
            if (dp[i] == -1)
                continue;
            for (int j = n - 1; j >= 0; j--)
            {
                int curr = arr[j];
                int gcd = __gcd(i, curr);
                if (dp[gcd] == -1)
                    dp[gcd] = dp[i] + dp[curr] + 1;
                else
                    dp[gcd] = min(dp[gcd], dp[i] + dp[curr] + 1);
            }
        }
        cout << dp[1] + n - 1 << endl;
    }
}