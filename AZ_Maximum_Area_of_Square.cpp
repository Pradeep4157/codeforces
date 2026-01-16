#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so one way is that we keep traversing in the grid

    and if we get and unvisited then start a dfs from there..

    the dfs goes like this..

    which ever cell we goto that's the LEFT top corner of the current square ..

    and then we check the LEFT diagonal square it will have the prev len of square now for this cell to be included

    we need that many 1 cells above and LEFT of this .. if we find that then we write dp[i][j] = dp[i-1][j-1] + 1..

    and update global res = max( res, dp[i][j])...

    and move to i+1,j+1..

    once we dont get that condition then we break..

    incase LEFT diagonal is not there then we assume its zero ..

    actually we dont need to traverse top and LEFT to find how many to the LEFT of this and top

    of this are actually 1 we can precompute that ..


*/
vector<vector<int>> dp;
vector<vector<bool>> vis;
int res;
int n, m;
vector<vector<int>> top;
vector<vector<int>> LEFT;
bool isvalid(int i, int j, vector<vector<int>> &arr)
{
    return (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == 1);
}
void dfs(int i, int j, vector<vector<int>> &arr)
{
    if (!isvalid(i, j, arr))
    {
        return;
    }
    // now cells are valid..
    int req = 0;

    if (isvalid(i - 1, j - 1, arr))
    {
        req = dp[i - 1][j - 1];
    }
    // now this req amount should be present in top and LEFT..

    int extra_addition = min(LEFT[i][j], top[i][j]);
    extra_addition = min(extra_addition, req);
    vis[i][j] = 1;

    dp[i][j] = extra_addition + 1;
    res = max(res, (extra_addition + 1) * (extra_addition + 1));
    dfs(i + 1, j + 1, arr);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        res = 0;
        dp.assign(n, vector<int>(m, 0));
        top.assign(n, vector<int>(m, 0));
        LEFT.assign(n, vector<int>(m, 0));

        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        }
        // precomputing LEFT values..
        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 0)
                {
                    curr = 0;
                }
                LEFT[i][j] = curr;
                if (arr[i][j] == 1)
                    curr++;
            }
        }

        // precomputing top values..
        for (int j = 0; j < m; j++)
        {
            int curr = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i][j] == 0)
                    curr = 0;

                top[i][j] = curr;
                if (arr[i][j] == 1)
                    curr++;
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //         cout << top[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;
        vis.assign(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == false && arr[i][j] == 1)
                {
                    // then we do dfs for this..
                    dfs(i, j, arr);
                }
            }
        }
        // for (auto a : dp)
        // {
        //     for (auto b : a)
        //         cout << b << " ";
        //     cout << endl;
        // }
        cout << res << endl;
    }
    return 0;
}
