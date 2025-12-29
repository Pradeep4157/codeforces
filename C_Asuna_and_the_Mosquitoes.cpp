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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        ll res = 1;
        bool oddfound = false, evenfound = false;
        ll biggesteven = 0, biggestodd = 0;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] & 1)
            {
                res += arr[i] - 1;
                oddfound = 1;
                biggestodd = max(biggestodd, arr[i]);
            }

            else
            {
                res += arr[i];
                evenfound = 1;
                biggesteven = max(biggesteven, arr[i]);
            }
        }
        if (oddfound == false)
        {
            cout << biggesteven << endl;
        }
        else if (evenfound == false)
        {
            cout << biggestodd << endl;
        }

        else
            cout << res << endl;
    }
    return 0;
}
