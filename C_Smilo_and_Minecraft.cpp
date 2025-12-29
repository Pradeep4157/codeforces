#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> arr(n, vector<char>(m));
        vector<vector<int>> prefix(n, vector<int>(m)), suffix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        }
        // prefix and suffix creation
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 'g')
                    prefix[i][j]++;
                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];
            }
            for (int j = m - 1; j >= 0; j--)
            {
                if (arr[i][j] == 'g')
                    suffix[i][j]++;
                if (j < m - 1)
                    suffix[i][j] += suffix[i][j + 1];
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '.')
                {
                    // can bomb this
                    int left = j - k;
                    int right = j + k;
                    int up = i - k + 1;
                    up = max(up, 0LL);
                    int down = i + k - 1;
                    down = min(down, n - 1);

                    // right of the square collection
                    int curr = 0;
                    if (right < m)
                    {
                        for (int z = up; z <= down; z++)
                        {
                            curr += suffix[z][right];
                        }
                    }

                    // left of square collection
                    if (left >= 0)
                    {
                        for (int z = up; z <= down; z++)
                        {
                            curr += prefix[z][left];
                        }
                    }
                    // collecting gold above square
                    for (int z = up - 1; z >= 0; z--)
                    {
                        curr += suffix[z][0];
                    }
                    // collecting gold below square
                    for (int z = down + 1; z < n; z++)
                    {
                        curr += suffix[z][0];
                    }
                    res = max(res, curr);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
