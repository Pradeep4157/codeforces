#include <bits/stdc++.h>
#define int long long
using namespace std;
int calc(vector<vector<int>> &arr, int row, int col, int maxi)
{
    int n = arr.size(), m = arr[0].size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == maxi && i != row && j != col)
                res++;
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
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        }
        int maxele = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                maxele = max(maxele, arr[i][j]);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (arr[i][j] == maxele)
                    count++;
        }
        if (count == 1)
        {
            cout << maxele - 1 << endl;
            continue;
        }
        int xf = -1, xs = -1, yf = -1, ys = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == maxele)
                {
                    if (xf == -1)
                    {
                        xf = i, yf = j;
                    }
                    else
                    {
                        if (xf != i && yf != j)
                        {
                            xs = i;
                            ys = j;
                            break;
                        }
                    }
                }
            }
        }

        int res = maxele;
        int curr1 = calc(arr, xf, ys, maxele);
        int curr2 = calc(arr, xs, yf, maxele);
        int curr3 = calc(arr, xf, yf, maxele);
        int curr4 = calc(arr, xs, ys, maxele);
        if (curr1 == 0 || curr2 == 0 || curr3 == 0 || curr4 == 0)
        {
            cout << maxele - 1 << endl;
        }
        else
            cout << maxele << endl;
    }
    return 0;
}
