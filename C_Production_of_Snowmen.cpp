#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


first find the valid k's for all j's then find

all the valid j's for i's that should do it..


but for comparing all i,j or j,k

also takes n cube


since we need < so all the values should be lesser than the next one..

>= all the values of next array

then 0..








*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> first(n), second(n), third(n);
        for (int i = 0; i < n; i++)
            cin >> first[i];
        for (int i = 0; i < n; i++)
            cin >> second[i];
        for (int i = 0; i < n; i++)
            cin >> third[i];
        vector<int> kforj(n);
        int res = n * n * n;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int k = 0; k < n; k++)
        {
            if (third[k] > second[0])
                dp[0][k] = 1;
        }
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (third[k] > second[j])
                {
                    int prev_index = k - 1;
                    prev_index += n;
                    prev_index %= n;
                    if (dp[j - 1][prev_index] == 1)
                        dp[j][k] = 1;
                }
            }
        }
        vector<vector<int>> dp1(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            if (second[j] > first[0])
                dp1[0][j] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (second[j] > first[i])
                {
                    int prev_index = j - 1;
                    prev_index += n;
                    prev_index %= n;
                    if (dp1[i - 1][prev_index] == 1)
                        dp1[i][j] = 1;
                }
            }
        }
        int F = 0;
        int S = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp1[n - 1][i] == 1)
                F++;
            if (dp[n - 1][i] == 1)
                S++;
        }
        cout << (F * S * n) << endl;
        // now i have some set of indexes for n..
    }
    return 0;
}
