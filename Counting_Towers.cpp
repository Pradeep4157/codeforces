#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = (int)(1e9 + 7);
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> dp(1000001, vector<int>(2, 0));
    dp[1][0] = 1, dp[1][1] = 1;
    for (int i = 1; i < 1000000; i++)
    {
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i + 1][0] = (dp[i][0] * 2) % mod;
        dp[i + 1][0] = (dp[i + 1][0] + dp[i][1]) % mod;
        dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % mod;
        dp[i + 1][1] = (dp[i + 1][1] + 4 * dp[i][1]) % mod;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << endl;
    }
    return 0;
}
