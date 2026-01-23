#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    either i choose to sell 0 or 1 or 2..
    dp..
*/
int n;
vector<vector<int>> dp;
vector<int> arr;
int recursion(int i, int left)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][left] != -1)
        return dp[i][left];
    // i choose to sell 0..
    int res = recursion(i + 1, left + 1);
    res = max(res, arr[i] + recursion(i + 1, left));
    if (left >= 1)
    {
        res = max(res, 2 * arr[i] + recursion(i + 1, left - 1));
    }
    return dp[i][left] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr.resize(n);
        dp.assign(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << (recursion(0, 0)) << endl;
    }
    return 0;
}
