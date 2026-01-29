#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so we need to color the grid such that for every row once a black cell starts the remaining cells are going to be

    black

    same for every column from top once a cell is black all the below ones are going to black as well..

    for every row :

        we iterate and now if we choose to color from this cell then all the right should be black , all the below should be black..

        also  all the left should be white and all the rows above should  be white..


    its a dp problem where i decide whether to color this cell black or white..

    and at the end return the min of whatever it is ..

    for any cell i,j  if i want to color that as black then the cost is no of white cells in right,bottom

    so we go from bottom right cell and for every cell we see that if we want to paint this black then no of white in right..

    + min(prefix of dp[i+1][0..j])

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int m = n;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int j = 0;
        for (auto a : s)
        {
            if (a == '.')
            {
                arr[i][j] = 0;
            }
            else
                arr[i][j] = 1;
            j++;
        }
    }
    vector<vector<int>> suffix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                suffix[i][j]++;
        }
        for (int j = m - 2; j >= 0; j--)
        {
            suffix[i][j] += suffix[i][j + 1];
        }
    }

    vector<vector<int>> prefix_dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        // if i want to keep all white..
        {
            int prev_white = suffix[i][0];
            int prev_black = n - prev_white;
            int curr_cost = prev_black;
            if (i < n - 1)
            {
                curr_cost += prefix_dp[i + 1][n];
            }
            dp[i][n] = curr_cost;
        }
        for (int j = m - 1; j >= 0; j--)
        {
            // if i choose to make this black..
            // first cost is no of right white cells..
            int curr_cost = suffix[i][j];
            // also prev shoudl be white..
            if (j > 0)
            {
                int prev_white = suffix[i][0] - suffix[i][j];
                int prev_black = j - prev_white;
                curr_cost += prev_black;
            }
            // and then the cost is min of below prefix dp..
            if (i < n - 1)
            {
                curr_cost += prefix_dp[i + 1][j];
            }

            dp[i][j] = curr_cost;
        }
        for (int j = 0; j <= m; j++)
        {
            prefix_dp[i][j] = dp[i][j];
            if (j)
            {
                prefix_dp[i][j] = min(prefix_dp[i][j - 1], prefix_dp[i][j]);
            }
        }
    }

    int res = LLONG_MAX;
    for (int j = 0; j <= m; j++)
    {
        res = min(res, dp[0][j]);
    }
    cout << res << endl;
    return 0;
}
