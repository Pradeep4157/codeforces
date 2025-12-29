#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    there should be exaclty k  ways so if in any way i can fill any x

    rows then remaining is just first cell R and all other cells L

    but when k == n*n - 1 that is when we cant make it

    when k = some rows filled + row - 1 then we need to point that down and

    rest rows with first R and all left
*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k == (n * n) - 1)
        {
            cout << "NO" << endl;
            continue;
        }

        int fully = (k / n);

        int rem = (fully + 1) * n % k;

        vector<vector<char>> res(n, vector<char>(n));

        if (rem == 1)
        {
            for (int i = 0; i < fully; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    res[i][j] = 'U';
                }
            }
            for (int j = 0; j < n; j++)
            {
                res[fully][j] = 'U';
                if (j == n - 1)
                    res[fully][j] = 'D';
            }
        }
        else
        {
            for (int i = 0; i < fully; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    res[i][j] = 'U';
                }
            }
            for (int j = 0; j < n - rem; j++)
            {
                res[fully][j] = 'U';
            }
            res[fully][n - rem] = 'R';
            for (int j = n - rem + 1; j < n; j++)
            {
                res[fully][j] = 'L';
            }
        }
        for (int i = fully + 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                    res[i][j] = 'R';
                else
                    res[i][j] = 'L';
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << res[i][j];
            cout << endl;
        }
    }
    return 0;
}
