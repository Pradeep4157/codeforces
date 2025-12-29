#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:



*/
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
bool isvalid(int x, int y, int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        int val = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = val++;
            }
        }
        val--;
        int res = 1;
        for (int i = 0; i < n; i++)
        {

            for (int z = 0; z < n; z++)
            {
                // cout << arr[i][z] << endl;
                int curr = arr[i][z];
                for (int j = 0; j < 4; j++)
                {
                    int nextx = i + dx[j];
                    int nexty = z + dy[j];
                    if (isvalid(nextx, nexty, n))
                    {
                        curr += arr[nextx][nexty];
                    }
                }
                // cout << curr << endl;
                res = max(res, curr);
            }
        }
        cout << res << endl;
    }
    return 0;
}
