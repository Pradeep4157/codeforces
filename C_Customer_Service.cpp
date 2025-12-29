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
        vector<vector<ll>> arr(n, vector<ll>(n));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        vector<ll> suffix(n, 0);
        for (ll i = 0; i < n; i++)
        {
            ll suffixsum = 0;
            for (ll j = n - 1; j >= 0; j--)
            {
                if (arr[i][j] == 1)
                    suffixsum++;
                else
                    break;
            }
            suffix[i] = suffixsum;
        }
        sort(suffix.begin(), suffix.end());
        ll mex = 1;
        int size = suffix.size();
        for (int i = 0; i < size; i++)
        {
            if (suffix[i] >= mex)
            {
                mex++;
            }
        }
        cout << min(n, mex) << endl;
    }
    return 0;
}