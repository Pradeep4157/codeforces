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
        int n;
        cin >> n;
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        if (arr[n - 1] != b[n - 1])
        {
            cout << "NO" << endl;
            continue;
        }
        bool ok = true;
        unordered_map<int, int> og, changed;
        og[n - 1] = arr[n - 1];
        changed[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] == b[i])
            {
                og[i] = arr[i];
                changed[i] = arr[i];
            }
            else
            {
                int first = og[i + 1];
                int second = changed[i + 1];
                if (((first ^ arr[i]) != b[i]) && ((second ^ arr[i]) != b[i]))
                {
                    ok = false;
                    break;
                }
                og[i] = arr[i];
                changed[i] = b[i];
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
