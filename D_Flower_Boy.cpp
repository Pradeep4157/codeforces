#include <bits/stdc++.h>
#define int long long
using namespace std;

int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        int res = LLONG_MAX;
        vector<int> prefix(m, INT_MAX), suffix(m, INT_MIN);
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (j >= m)
                break;
            if (arr[i] >= b[j])
            {
                prefix[j] = i;
                i++;
                j++;
            }
            else
                i++;
        }
        i = n - 1;
        j = m - 1;
        while (i >= 0)
        {
            if (j < 0)
                break;
            if (arr[i] >= b[j])
            {
                suffix[j] = i;
                i--;
                j--;
            }
            else
                i--;
        }

        if (prefix[m - 1] != INT_MAX)
        {
            cout << 0 << endl;
            continue;
        }
        if (m == 1)
        {
            if (prefix[0] != INT_MAX)
            {
                cout << 0 << endl;
            }
            else
                cout << b[0] << endl;
            continue;
        }
        for (int i = 1; i < m - 1; i++)
        {
            if (prefix[i - 1] < suffix[i + 1])
            {
                res = min(res, b[i]);
            }
        }
        if (suffix[1] != INT_MIN)
        {
            res = min(res, b[0]);
        }
        if (prefix[m - 2] != INT_MAX)
        {
            res = min(res, b[m - 1]);
        }
        if (res == LLONG_MAX)
        {
            cout << -1 << endl;
            continue;
        }
        else
            cout << res << endl;
    }
    return 0;
}
