#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        in this we just need to return the len of lis..

        its not subsequence it is substring..

        so the BF IS :

        some  left pointer of a string and left pointer of b string..

        and then another loop to check

*/
string a, b;
int n, m;
vector<vector<int>> dp;
int ans;
int recursion(int i, int j)
{
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
    {

        return dp[i][j];
    }

    int res = 0;
    if (a[i] == b[j])
    {
        res = 1 + recursion(i + 1, j + 1);
    }

    recursion(i + 1, j);
    recursion(i, j + 1);

    ans = max(ans, res);
    return dp[i][j] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        n = a.size();
        m = b.size();
        dp.assign(n, vector<int>(m, -1));
        ans = 0;
        recursion(0, 0);
        cout << ans << endl;
    }
    return 0;
}
