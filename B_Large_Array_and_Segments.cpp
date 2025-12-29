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
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        vector<ll> suffix(n, 0), prefix(n, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i] += arr[i];
            if (i > 0)
                prefix[i] += prefix[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] += arr[i];
            if (i < n - 1)
                suffix[i] += suffix[i + 1];
        }
        ll res = 0;
        ll sum = accumulate(arr.begin(), arr.end(), 0LL);
        ll total = sum * k;
        if (total < x)
        {
            cout << 0 << endl;
            continue;
        }

        // can be found with the suffix
        if (x <= sum)
        {
            int index = n - 1;
            while (index >= 0 && suffix[index] < x)
            {
                index--;
            }

            int firstindex = 0;
            ll elements = n * k;
            ll rem1 = elements - (n - index - 1);
            while (firstindex < n && prefix[firstindex] < x)
            {
                firstindex++;
            }
            ll rem2 = elements - firstindex;
            cout << (rem1) << endl;
        }
        // will have to divide and get close
        else
        {

            ll div = x / sum;

            ll rem = x - (div * sum);
            if (rem == 0)
            {
                ll remaining = (k * n) - (div * n) + 1;
                cout << remaining << endl;
                continue;
            }
            int index = n - 1;
            while (index >= 0 && suffix[index] < rem)
            {
                index--;
            }

            ll elements = n * k;
            ll used = div * n;

            used += (n - index - 1);
            int firstindex = 0;
            while (firstindex < n && prefix[firstindex] < rem)
            {
                firstindex++;
            }
            ll used2 = (div * n);
            used2 += (firstindex);

            cout << (elements - (used)) << endl;
        }
    }
    return 0;
}
