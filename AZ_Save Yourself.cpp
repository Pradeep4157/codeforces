#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we need to reach boundary ..

    if poss true, break else return false..


*/
int n, m;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
bool isvalid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    int startx, starty;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    deque<vector<int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                q.push_back({i, j, 0});
            }
            else if (arr[i][j] == 'M')
            {
                q.push_front({i, j, 1});
            }
            if (arr[i][j] != '.')
            {
                vis[i][j] = 1;
            }
            if (arr[i][j] == 'A')
                vis[i][j] = false;
            if (arr[i][j] == 'M')
                vis[i][j] = false;
        }
    }
    int time = 0;
    bool found = false;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            vector<int> curr = q.front();
            q.pop_front();

            int x = curr[0];
            int y = curr[1];
            int type = curr[2];

            if (vis[x][y])
            {
                continue;
            }
            if (type == 0 && (x == n - 1 || y == m - 1 || x == 0 || y == 0))
            {

                found = 1;
                break;
            }
            vis[x][y] = 1;

            // else it is either monster or has not reached boundary..
            for (int z = 0; z < 4; z++)
            {
                int nextx = x + dx[z];
                int nexty = y + dy[z];

                if (isvalid(nextx, nexty) && !vis[nextx][nexty])
                {
                    // we can go there..
                    q.push_back({nextx, nexty, type});
                }
            }
        }
        if (found == true)
            break;
        time++;
    }
    if (found)
    {
        cout << "YES" << endl;
        cout << time << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}