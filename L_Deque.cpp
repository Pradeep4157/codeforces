#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    is it just greedy ..

    10 100 1000  90

    not greedy ..



*/
vector<int> arr;
int n;
vector<vector<int>> dp;
int recursion(int left, int right, bool first)
{
    if (left == right)
    {
        if (first)
            return arr[right];
        else
            return -arr[right];
    }
    // now if first then maximize else minimize..
    if (dp[left][right] != -1)
        return dp[left][right];
    int res = LLONG_MIN;
    if (first)
    {
        int FIRST = arr[left] + recursion(left + 1, right, 0);
        int SECOND = max(res, arr[right] + recursion(left, right - 1, 0));
        res = max(FIRST, SECOND);
    }
    else
    {
        res = recursion(left + 1, right, 1) - arr[left];
        res = min(res, recursion(left, right - 1, 1) - arr[right]);
    }
    return dp[left][right] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    arr.resize(n);
    dp.assign(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << (recursion(0, n - 1, 1)) << endl;
    return 0;
}
