#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));

    for (int i = 0; i < q; ++i)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        diff[a][b] += 1;
        diff[x + 1][b] -= 1;
        diff[a][y + 1] -= 1;
        diff[x + 1][y + 1] += 1;
    }

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            grid[i][j] = diff[i][j] + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            grid[i][j] += 1;
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

    if (grid[1][1] % 2 == 1)
    {
        
        q.push({1, 1});
        visited[1][1] = true;
    }

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while (!q.empty())
    {
        auto curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();

        for (auto next : directions)
        {
            int dx = next.first;
            int dy = next.second;
            int nx = x + dx, ny = y + dy;
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= m &&
                !visited[nx][ny] && (grid[nx][ny] % 2) == 1)
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    if (visited[n][m])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}