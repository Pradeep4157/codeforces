#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    not gym or contest for 2 cons days..

    prev count..



*/
int n;
vector<vector<int>> dp;
int recursion(int i, int prev, vector<int> &arr)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][prev] != -1)
        return dp[i][prev];
    int res = 1 + recursion(i + 1, 0, arr);
    if (prev == 0)
    {
        //  then here we can do it..
        if (arr[i] == 0)
            res = min(res, 1 + recursion(i + 1, arr[i], arr));
        else
            res = min(res, recursion(i + 1, arr[i], arr));
    }
    else if (prev == 3)
    {
        if (arr[i] == 3)
        {
            // then still we have 2 options.
            res = min(res, recursion(i + 1, prev, arr));
        }
        else if (arr[i] == 0)
        {
            // then we need to take rest..
            res = min(res, 1 + recursion(i + 1, arr[i], arr));
        }
        else
        {
            // now we do whatever it is..
            res = min(res, recursion(i + 1, arr[i], arr));
        }
    }
    else
    {
        // now we might have to res.t.

        // we have done some thing yesterday..
        if (arr[i] == 0)
        {
            res = min(res, 1 + recursion(i + 1, 0, arr));
        }
        else if (arr[i] == 3)
        {
            if (prev == 1)
                res = min(res, recursion(i + 1, 2, arr));
            else if (prev == 2)
                res = min(res, recursion(i + 1, 1, arr));
        }
        else
        {
            if (arr[i] == prev)
            {
                res = min(res, 1 + recursion(i + 1, arr[i], arr));
            }
            else
            {
                res = min(res, recursion(i + 1, arr[i], arr));
            }
        }
    }
    return dp[i][prev] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> n;
    vector<int> arr(n);
    dp.assign(n + 1, vector<int>(10, -1));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << recursion(0, 0, arr) << endl;

    return 0;
}
