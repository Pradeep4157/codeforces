#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so same thing i can move right or down and from left top reach right bottom

    here we have option to unblock some blocked items..

    so just k para extra that will tell how many i can unblock more..


*/
const int mod = (int)(1e9 + 7);
int n, m;
bool isvalid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}
vector<vector<vector<int>>> dp;
int recursion(int i, int j, int k_left, vector<vector<int>> &arr)
{
    if (i >= n || j >= m)
        return 0;
    else if ((i == n - 1) && (j == m - 1))
        return 1;
    if (dp[i][j][k_left] != -1)
        return dp[i][j][k_left];
    int res = 0;
    if (isvalid(i + 1, j))
    {
        if (arr[i + 1][j] == 1)
        {
            if (k_left > 0)
            {
                res += recursion(i + 1, j, k_left - 1, arr);
                res %= mod;
            }
        }
        else
        {
            res += recursion(i + 1, j, k_left, arr);
            res %= mod;
        }
    }
    if (isvalid(i, j + 1))
    {
        if (arr[i][j + 1] == 1)
        {
            if (k_left > 0)
            {
                res += recursion(i, j + 1, k_left - 1, arr);
                res %= mod;
            }
        }
        else
        {
            res += recursion(i, j + 1, k_left, arr);
            res %= mod;
        }
    }
    return dp[i][j][k_left] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        int k;
        cin >> n >> m >> k;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        }
        dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        if (arr[0][0] == 1)
        {
            if (k == 0)
            {
                cout << 0 << endl;
                continue;
            }
            else
                k--;
        }
        cout << (recursion(0, 0, k, arr)) << endl;
    }
    return 0;
}
