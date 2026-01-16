#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    3 operations :
        insert , delete or replace

    if same :
        i+1,j+1

    if insert :
        i+1,j
    else if delete :
        i,j+1

    else replace i+1,j+1

    base :
        if i>=n :
            return m - j
        because we need to insert these many in a ...

        else if j >= m :
            return n - i

        because we need to insert these many at the end..

*/
string a, b;
int n, m;
vector<vector<int>> dp;
int recursion(int i, int j)
{
    if (i >= n)
    {
        return m - j;
    }
    else if (j >= m)
    {
        return n - i;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    // if same no op needed..
    int res = LLONG_MAX;
    if (a[i] == b[j])
    {
        res = recursion(i + 1, j + 1);
    }
    // insertion..
    res = min(res, 1 + recursion(i, j + 1));
    // deletion..
    res = min(res, 1 + recursion(i + 1, j));
    // updation..
    res = min(res, 1 + recursion(i + 1, j + 1));
    return dp[i][j] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    n = a.size();
    m = b.size();
    dp.assign(n, vector<int>(m, -1));
    cout << (recursion(0, 0)) << endl;
    return 0;
}
