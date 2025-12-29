#include <bits/stdc++.h>
#define ll int64_t
#define pb push_back
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
        vector<ll> even, odd;
        for (ll i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            if (ele & 1)
                odd.pb(ele);
            else
                even.pb(ele);
        }
        if (n == 1 || even.empty() || odd.empty())
        {
            cout << 0 << endl;
            continue;
        }
        ll evensize = even.size();
        ll oddsize = odd.size();

        ll index = -1;
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        ll largestodd = odd[oddsize - 1];
        for (ll i = 0; i < evensize; i++)
        {
            if (even[i] > largestodd)
            {
                index = i;
                break;
            }
            else
            {
                largestodd += even[i];
            }
        }

        if (index == -1)
        {
            cout << evensize << endl;
            continue;
        }
        else
        {
            ll totalsteps = index;
            totalsteps++;
            ll rem = evensize - index;
            totalsteps += rem;
            cout << totalsteps << endl;
        }
    }
    return 0;
}
