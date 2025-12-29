#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> cost(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= 1; j--)
        {
            if (cost[i] > j)
                continue;
            dp[j] = max(dp[j], dp[j - cost[i]] + pages[i]);
        }
    }
    cout << dp[x] << endl;

    return 0;
}
