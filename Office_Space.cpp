#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
int n, m;
vector<vector<bool>> vis;
bool isvalid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int dfs(int curri, int currj, vector<vector<char>> &arr)
{
    int res = 1;
    vis[curri][currj] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nexti = curri + dx[i];
        int nextj = currj + dy[i];
        if (isvalid(nexti, nextj) && arr[nexti][nextj] == '0' && !vis[nexti][nextj])
        {
            res += dfs(nexti, nextj, arr);
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int index = 1;
    while (t--)
    {

        cin >> n >> m;
        vector<vector<char>> arr(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        int res = 0;

        vis.assign(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '1' || vis[i][j] == 1)
                    continue;
                int curr = dfs(i, j, arr);

                // cout << i << ":" << j << endl;
                res = max(res, curr);
            }
        }
        cout << "Floor #" << index << ": " << res << endl;
        index++;
    }
    return 0;
}
