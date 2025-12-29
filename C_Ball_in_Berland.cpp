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
        int boys, girls, k;
        cin >> boys >> girls >> k;
        vector<int> first(k), second(k);
        for (int i = 0; i < k; i++)
            cin >> first[i];
        for (int i = 0; i < k; i++)
            cin >> second[i];
        vector<int> dp(boys + 1, 0);
        vector<int> vis(girls + 1, 0);
        for (int i = 0; i < k; i++)
        {
            dp[first[i]]++;
            vis[second[i]]++;
        }

        int sum = accumulate(dp.begin(), dp.end(), 0LL);
        int res = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            sum -= dp[i];
            res += (dp[i] * sum);
        }
        for (int i = 0; i < vis.size(); i++)
        {
            res -= (vis[i] * (vis[i] - 1)) / 2;
        }
        cout << res << endl;
    }
    return 0;
}
