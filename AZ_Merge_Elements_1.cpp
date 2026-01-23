#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so we will have l and r and we will traverse i from l..r - 1

    and if we choose that i as breaking point then

        recursion(l,i) + recursion(i+1,r) + sum(l..i)*sum(i+1..r)




*/
vector<int> arr;
int n;
const int mod = 100;
vector<vector<int>> dp;
vector<int> prefix;
int recursion(int left, int right)
{
    if (left == right)
    {
        // then there is no more choice..
        return 0;
    }
    if (dp[left][right] != -1)
        return dp[left][right];
    // now we have option from i...r - 1
    int ans = LLONG_MAX;
    for (int i = left; i < right; i++)
    {
        int res = recursion(left, i) + recursion(i + 1, right);
        // now subarray addition..
        int left_sum = 0, right_sum = 0;
        left_sum = prefix[i];
        if (left)
            left_sum -= prefix[left - 1];
        right_sum = prefix[right];
        right_sum -= prefix[i];
        left_sum %= mod;
        right_sum %= mod;
        // for (int j = left; j <= right; j++)
        // {
        //     if (j <= i)
        //         left_sum += arr[j];
        //     else
        //         right_sum += arr[j];
        //     left_sum %= mod;
        //     right_sum %= mod;
        // }
        res += (left_sum * right_sum);
        ans = min(ans, res);
    }
    return dp[left][right] = ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    arr.resize(n);
    dp.assign(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    prefix.assign(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        prefix[i] = sum;
    }
    cout << recursion(0, n - 1) << endl;
    return 0;
}
