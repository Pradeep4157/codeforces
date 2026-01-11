#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we need to select k subarrays of size m ..

    and each of them should be dist..

    select in such a way that sum of all these subarrays should be maximized..


*/
int n, m, k;
vector<vector<int>> dp;
int recursion(int i, int k, vector<int> &arr)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][k] != -1)
        return dp[i][k];
    int res = recursion(i + 1, k, arr);
    if (k && i <= n - m)
    {
        int curr_sum = 0;
        for (int j = i; j < i + m; j++)
        {
            curr_sum += arr[j];
        }
        res = max(res, curr_sum + recursion(i + m, k - 1, arr));
    }
    return dp[i][k] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp.assign(n, vector<int>(k + 1, -1));
    cout << recursion(0, k, arr) << endl;

    return 0;
}
