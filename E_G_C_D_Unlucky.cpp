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
        vector<int> prefix(n), suffix(n);
        for (int i = 0; i < n; i++)
        {
            cin >> prefix[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> suffix[i];
        }
        // cout << __gcd(36, 117) << endl;
        bool ok = 1;

        if (prefix[n - 1] != suffix[0])
        {

            ok = false;
        }
        // prefix validation
        for (int i = 0; i < n - 1; i++)
        {
            if (prefix[i + 1] > prefix[i] || __gcd(prefix[i + 1], prefix[i]) != prefix[i + 1])
            {

                ok = false;
                break;
            }
        }
        // suffix validation
        for (int i = n - 1; i > 0; i--)
        {
            if (suffix[i - 1] > suffix[i] || __gcd(suffix[i - 1], suffix[i]) != suffix[i - 1])
            {

                ok = false;
                break;
            }
        }
        if (ok == false)
        {

            cout << "NO" << endl;
        }
        else
        {
            bool ok = 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (__gcd(prefix[i], suffix[i + 1]) != suffix[0])
                {
                    ok = false;
                }
            }
            cout << ((ok) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
