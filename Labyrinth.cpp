#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int n, m;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<char> whichone = {'D', 'U', 'R', 'L'};
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isvalid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    int currx = -1, curry = -1;
    int destx = -1, desty = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                currx = i;
                curry = j;
            }
            else if (arr[i][j] == 'B')
            {
                destx = i;
                desty = j;
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    q.push({currx, curry});
    bool found = false;
    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();

        int currx = front.first;
        int curry = front.second;
        if (vis[currx][curry])
            continue;
        vis[currx][curry] = 1;
        if (arr[currx][curry] == 'B')
        {
            found = 1;
            cout << "YES" << endl;
            break;
        }
        for (int z = 0; z < 4; z++)
        {
            int nextx = dx[z] + currx;
            int nexty = dy[z] + curry;

            if (isvalid(nextx, nexty) && !vis[nextx][nexty] && arr[nextx][nexty] != '#')
            {
                q.push({nextx, nexty});
                par[nextx][nexty] = {currx, curry};
            }
        }
    }
    if (found == false)
    {
        cout << "NO" << endl;
        return 0;
    }
    int x = destx, y = desty;

    vector<char> res;
    while (true)
    {
        if (par[x][y].first == -1)
        {
            break;
        }
        int parx = par[x][y].first;
        int pary = par[x][y].second;
        int diff_x = parx - x;
        int diff_y = pary - y;

        for (int z = 0; z < 4; z++)
        {
            int curr_first = dir[z].first;
            int curr_second = dir[z].second;
            if (curr_first == diff_x && curr_second == diff_y)
            {
                res.push_back(whichone[z]);
                break;
            }
        }
        // now make x , y as par..
        x = parx;
        y = pary;
    }
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto a : res)
        cout << a;
    cout << endl;
    return 0;
}
