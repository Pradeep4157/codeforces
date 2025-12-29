#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = (int)(1e9 + 7);
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == '*')
            break;
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[0][j] == '*')
            break;
        dp[0][j] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == '*')
                continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}
