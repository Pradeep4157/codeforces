#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so he will div apples in x/2 and x - (x/2)

    maybe instead of going form x -> k

    we can go from k - > x ...




*/
int k;
int N;
map<int, int> dp;
int recursion(int n)
{
    if (n < k)
        return (int)1e9;
    if (n == k)
        return 0;
    int new_n = ((n + 1) / 2);
    int res = 1 + recursion(new_n);
    return dp[n] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        dp.clear();
        cin >> N >> k;
        int res = recursion(N);
        if (res >= (int)1e9)
        {
            cout << -1 << endl;
        }
        else
            cout << res << endl;
    }
    return 0;
}
