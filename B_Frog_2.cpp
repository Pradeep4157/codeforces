#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int n, k;
vector<int> dp(n);
int recursion(int i, vector<int> &arr)
{
    if (i == n - 1)
    {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    int res = LLONG_MAX;
    for (int j = i + 1; j <= i + k; j++)
    {
        if (j >= n)
            break;
        res = min(res, abs(arr[j] - arr[i]) + recursion(j, arr));
    }
    return dp[i] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    dp.assign(n + 1, -1);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << (recursion(0, arr)) << endl;

    return 0;
}
