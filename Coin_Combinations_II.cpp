#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        for (int j = curr; j <= x; j++)
        {
            dp[j] = (dp[j - curr] + dp[j]) % mod;
        }
    }
    cout << dp[x] << endl;

    return 0;
}
