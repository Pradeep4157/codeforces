#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we can use dp here..

    so at any index i either choose to merge it with above one or adj .. 

    if i choose to merge arr[i][j] with above .. 

    then the score will be 


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int m = 3;
        vector<vector<int>> arr(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<vector<int>> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                pq.push({arr[i][j] + arr[i][j + 1], i, j, i, j + 1});
                if (i)
                {
                    pq.push({arr[i][j] + arr[i - 1][j], i, j, i - 1, j});
                }
            }
            // we can also use above cell..
        }

        int res = 0;
        while (k--)
        {
            if (pq.empty())
                break;
            vector<int> top = pq.top();
            pq.pop();
            int curr_sum = top[0];

            int x = top[1];
            int y = top[2];
            int x2 = top[3];
            int y2 = top[4];
            if (vis[x][y] || vis[x2][y2])
            {
                k++;
                continue;
            }
            vis[x][y] = 1;
            vis[x2][y2] = 1;
            res += curr_sum;
        }
        cout << res << endl;
    }
    return 0;
}
