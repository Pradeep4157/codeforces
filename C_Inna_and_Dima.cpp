#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
vector<char> check = {'D', 'I', 'M', 'A'};
vector<vector<int>> dp;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
int n;
int m;
ll recursion(int x, int y, int index, vector<vector<char>> &arr)
{
    // out of bounds condition and char mismatch check
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] != check[index])
        return 0;
    // infinite check
    if (dp[x][y] == -2)
        return INT_MAX;
    // already visited check in some other recursion
    if (dp[x][y] != -1)
        return dp[x][y];
    // checking neighbors
    ll res = 0;
    dp[x][y] = -2;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        ll currres = recursion(nextx, nexty, (index + 1) % 4, arr);
        if (currres >= INT_MAX)
            return INT_MAX;
        res = max(res, currres);
    }
    if (index == 3)
        res++;
    return dp[x][y] = res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    ll res = 0;
    bool poorinna = false;

    // dp.clear();
    dp.resize(n, vector<int>(m, -1));
    //  dp.resize(n, vector<vector<int>>(m, vector<int>(4, -1)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'D')
            {
                ll currres = recursion(i, j, 0, arr);
                if (currres == INT_MAX)
                {
                    poorinna = 1;
                    break;
                }
                res = max(res, currres);
            }
            if (poorinna)
                break;
        }
    }
    if (poorinna == true)
    {
        cout << "Poor Inna!" << endl;
    }
    else if (res == 0)
    {
        cout << "Poor Dima!" << endl;
    }
    else
        cout << res << endl;

    return 0;
}
