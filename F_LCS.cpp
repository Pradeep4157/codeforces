#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    first lets do the bf part where the return type is string and dp

    is going to be vector of vector of strings..

    instead if we store int which is the longest subsequence found till now ..

    then maybe somehow we can extract the subsequence from the dp array..

    from the end the place where the subsequence increases  that means that char is used in the final subsequence

    mostly..
*/
string a, b;
int n, m;
vector<vector<int>> dp;
int recursion(int i, int j)
{
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int res = 0;
    if (a[i] == b[j])
    {
        res = 1 + recursion(i + 1, j + 1);
    }
    else
    {

        int res1 = recursion(i + 1, j);
        int res2 = recursion(i, j + 1);
        res = max(res1, res2);
    }
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
    recursion(0, 0);
    int i = 0, j = 0;
    string res;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            res += a[i];
            i++;
            j++;
        }
        else
        {
            if (i == n - 1)
            {
                j++;
            }
            else if (j == m - 1)
            {
                i++;
            }
            else
            {

                if (dp[i + 1][j] >= dp[i][j + 1])
                {
                    i++;
                }
                else
                    j++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
