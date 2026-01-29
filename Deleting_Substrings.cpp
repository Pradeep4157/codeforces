#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    some subsequence of s == t..

    and the between elements which we remove should be min..

    if that is true then if the subsequence === t then between we del..

    for a char in s..

    this is going to be some char in t..

    so the dp of this is going to be ..

    this is present at some indexes in t..

    m is only 100..

    so for every char of n we can bf where it can be placed..

    now if we choose some index then ..

    dp[index - 1] should be possible and


*/
int n, m;
string s;
string t;
static int dp[200005][105][2];
int recursion(int i, int j, bool deletion)
{
    if (j >= m)
    {
        // then we got a subsequence..
        if (i < n)
        {
            return 1;
        }
        else
            return 0;
    }
    if (i >= n)
    {
        // that means we didnt get subsequence here..
        return n + 1;
    }
    // now either we del..
    if (dp[i][j][deletion] != -1)
        return dp[i][j][deletion];
    int res;
    if (deletion)
    {
        // since deletion is going on so no addtion..
        res = recursion(i + 1, j, deletion);
    }
    else
    {

        res = 1 + recursion(i + 1, j, 1);
    }
    // now if we match..

    if (s[i] == t[j])
    {

        // if no deletion is going on then no cost.
        res = min(res, recursion(i + 1, j + 1, 0));
    }
    return dp[i][j][deletion] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {

        cin >> n >> m;
        cin >> s;
        cin >> t;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }

        int res = (recursion(0, 0, 0));

        if (res >= n)
        {
            cout << -1 << endl;
        }
        else
            cout << res << endl;
    }
    return 0;
}
