#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        if (k == n)
        {
            int count = 1;
            for (int i = 1; i < n; i += 2)
            {
                if (arr[i] != count)
                {
                    break;
                }
                count++;
            }
            cout << count << endl;
            continue;
        }
        else
        {
            ll maxinagroup = n - k + 1;
            bool possible = false;
            for (ll i = 0; i <= maxinagroup; i++)
            {
                // might be less than maxinagroup
                if (arr[i] != 1 && i != 0)
                {
                    possible = true;
                    break;
                }
            }

            if (possible)
            {
                cout << 1 << endl;
            }
            else if (arr[maxinagroup] != 1)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
    return 0;
}
