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
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        ll ele = arr[0];
        unordered_set<ll> st;
        for (ll i = 1; i < n; i++)
        {
            if (arr[i] % ele == 0)
            {
                st.insert(arr[i]);
            }
        }
        if (st.empty())
        {
            cout << "No" << endl;
            continue;
        }
        vector<ll> factors(st.begin(), st.end());
        ll curr = factors[0];
        for (ll i = 1; i < factors.size(); i++)
        {
            if (curr == ele)
                break;
            curr = __gcd(curr, factors[i]);
        }
        if (curr == ele)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
