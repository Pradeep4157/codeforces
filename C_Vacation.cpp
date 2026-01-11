#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        same activity cant be done for 2 days..



*/
int n;
vector<vector<int>> dp;
int recursion(int i, vector<vector<int>> &arr, int prev)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][prev] != -1)
        return dp[i][prev];
    int res = 0;
    if (prev != 0)
    {
        res = max(res, arr[i][0] + recursion(i + 1, arr, 0));
    }
    if (prev != 1)
    {
        res = max(res, arr[i][1] + recursion(i + 1, arr, 1));
    }
    if (prev != 2)
    {
        res = max(res, arr[i][2] + recursion(i + 1, arr, 2));
    }
    return dp[i][prev] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dp.assign(n + 1, vector<int>(4, -1));
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << (recursion(0, arr, 3)) << endl;
    return 0;

}
