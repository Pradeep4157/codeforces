
#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    the simple idea is that we first mark empty cells are X and keep a count of s and then we mark s - k X cells as . using dfs
*/
int n, m, k, s;
int rem;
vector<vector<char>> arr;
void dfs(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] != 'X' || rem == 0)
        return;
    arr[i][j] = '.';
    rem--;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    int x = -1, y = -1;
    arr.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '.')
            {
                arr[i][j] = 'X';
                s++;
                x = i, y = j;
            }
        }
    }
    rem = s - k;
    dfs(x, y);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j];
        cout << endl;
    }

    return 0;
}
