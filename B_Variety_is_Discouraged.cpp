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
        unordered_map<ll, ll> mp;
        for (auto a : arr)
        {
            mp[a]++;
        }

        ll l = 0, max_l = -1, max_r = -1;
        while (l < n)
        {
            while (l < n && mp[arr[l]] != 1)
            {
                l++;
            }
            if (l == n)
                break;
            ll r = l;
            while (r < n && mp[arr[r]] == 1)
                r++;
            r--;
            if (max_r - max_l <= r - l)
            {
                max_l = l;
                max_r = r;
            }
            l = r + 1;
        }
        if (max_l == -1 && max_r == -1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << max_l + 1 << " " << max_r + 1 << endl;
        }
    }
    return 0;
}
