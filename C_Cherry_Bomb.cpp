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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int sum = -1;
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (b[i] != -1)
            {
                found = 1;
                sum = a[i] + b[i];
                break;
            }
        }
        if (found == 1)
        {
            bool nott = false;
            for (int i = 0; i < n; i++)
            {
                if (b[i] != -1 && a[i] + b[i] != sum)
                {
                    nott = 1;
                    break;
                }
                if (b[i] == -1)
                {
                    if (a[i] + k < sum || a[i] > sum)
                    {
                        nott = 1;
                        break;
                    }
                }
            }

            if (nott)
            {
                cout << 0 << endl;
                continue;
            }
            cout << 1 << endl;
            continue;
        }
        else
        {
            int maxi = *max_element(a.begin(), a.end());
            int mini = *min_element(a.begin(), a.end());
            if (mini + k < maxi)
            {
                cout << 0 << endl;
                continue;
            }
            cout << mini + k - maxi + 1 << endl;
        }
    }
    return 0;
}
