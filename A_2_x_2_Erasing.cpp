#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    IN THE GRID THAT  HAVE BEEN GIVEN.
    I NEED TO FIND THE COUNT OF 2*2 GRID
    WHERE ALL ARE WHITE AFTER THIS I WILL
    JUST MOVE
    LOOKS LIKE A VARIATION OF PREFIX


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // WE WILL MAKE PREFIX
    vector<vector<int>> prefix(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[i][j] == '.' && arr[i][j + 1] == '.' && arr[i + 1][j] == '.' && arr[i + 1][j + 1] == '.')
            {
                prefix[i][j]++;
            }
            if (j)
                prefix[i][j] += prefix[i][j - 1];
        }
    }

    while (q--)
    {
        int u, d, l, r;

        cin >> u >> d >> l >> r;
        u--;
        d--;
        l--;
        r--;
        int res = 0;
        for (int i = u; i < d; i++)
        {
            int curr = prefix[i][r - 1];
            if (l)
                curr -= prefix[i][l - 1];
            res += curr;
            // cout << i << ":" << curr << endl;
        }
        cout << res << endl;
    }

    return 0;
}
