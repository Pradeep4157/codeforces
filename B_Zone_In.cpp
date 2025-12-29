#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    first i will create a queue of vector<int> where it would initially contain i,j,0


    here i , j are the object cells that are objects

    then for each cell we are going to all its adj cells and check if that is unvisited or the value of that cell is

    greater than current traversal then update that cell and add that to queue {i,j,currcount+1}

    after this traverse through the grid && if the grid dist < s then res++;
*/
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
bool isvalid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int dfs(int currx, int curry, vector<vector<int>> &dp, vector<vector<bool>> &vis, int s)
{
    int res = 1;
    vis[currx][curry] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nextx = currx + dx[i];
        int nexty = curry + dy[i];
        if (isvalid(nextx, nexty, dp.size(), dp[0].size()) && !vis[nextx][nexty] && dp[nextx][nexty] > s)
        {
            // then we can go here also
            res += dfs(nextx, nexty, dp, vis, s);
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("zone_in_input.txt", "r", stdin);
    freopen("b_output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    cerr << "Read test cases: " << t << endl;

    int index = 1;
    while (t--)
    {
        cerr << "Running test case: " << index << endl;

        int n, m, s;
        cin >> n >> m >> s;
        vector<vector<char>> arr(n, vector<char>(m));
        queue<vector<int>> q;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                if (j == 0 || i == 0 || i == n - 1 || j == m - 1)
                {
                    q.push({i, j, 1});
                    dp[i][j] = 1;
                }
                if (arr[i][j] == '#')
                {
                    q.push({i, j, 0});
                    dp[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int currx = curr[0];
            int curry = curr[1];
            int currdist = curr[2];

            for (int i = 0; i < 4; i++)
            {
                int nextx = currx + dx[i];
                int nexty = curry + dy[i];
                if (isvalid(nextx, nexty, n, m) && dp[nextx][nexty] > currdist + 1)
                {
                    dp[nextx][nexty] = currdist + 1;
                    q.push({nextx, nexty, currdist + 1});
                }
            }
        }
        int res = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && dp[i][j] > s)
                {
                    // then this might be the answer

                    res = max(res, dfs(i, j, dp, vis, s));
                }
            }
        }
        cout << "Case #" << index++ << ": ";
        cout << res << endl;
    }
    return 0;
}
