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
        int n;
        cin >> n;
        vector<int> p(n), d(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        // test
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({p[i], d[i], b[i]});
        }
        sort(arr.begin(), arr.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
             {
                ll res1= get<0>(a) * (get<1>(a) - (get<2>(a)));
                ll res2 =  get<0>(b) * (get<1>(b) - (get<2>(b)));
                return (res1>res2); });
        ll res = 0;
        ll currtime = 0;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            ll p = get<0>(arr[i]);
            ll d = get<1>(arr[i]);
            ll b = get<2>(arr[i]);
            if (d - (b + currtime) < 0)
            {
                index = i;
                break;
            }
            ll curr = p * (d - (b + currtime));
            res += curr;
            currtime += b;
        }
        vector<tuple<int, int, int>> rem;
        for (int i = index; i < n; i++)
        {
            rem.push_back(arr[i]);
        }
        sort(rem.begin(), rem.end(), [&](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
             {
            ll p1 = get<0>(a), d1 = get<1>(a), b1 = get<2>(a);
            ll p2 = get<0>(b), d2 = get<1>(b), b2 = get<2>(b);
        
            ll val1 = p1 * (d1 - (currtime + b1));
            ll val2 = p2 * (d2 - (currtime + b2));

            if (val1 == val2) {
                if (d1 != d2) return d1 < d2;
                if (b1 != b2) return b1 < b2;
                return p1 > p2;
            }
            return val1 < val2; });

        for (int i = 0; i < rem.size(); i++)
        {
            ll p = get<0>(rem[i]);
            ll d = get<1>(rem[i]);
            ll b = get<2>(rem[i]);

            ll curr = p * (d - (b + currtime));
            res += curr;
            currtime += b;
        }
        cout << res << endl;
    }
    return 0;
}
