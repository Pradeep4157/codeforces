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
        ll n, money;
        cin >> n >> money;
        vector<ll> temp;
        vector<ll> mon;
        for (int i = 0; i < n; i++)
        {
            ll ele;
            cin >> ele;
            temp.push_back(ele);
        }
        for (int i = 0; i < n; i++)
        {
            ll ele;
            cin >> ele;
            mon.push_back(ele);
        }
        vector<pair<ll, ll>> arr;
        for (int i = 0; i < n; i++)
        {
            ll first = temp[i];
            ll second = mon[i];
            arr.push_back({first, second});
        }

        sort(arr.rbegin(), arr.rend());
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            ll cost = arr[i].first;
            ll freq = arr[i].second;
            if (cost > money)
                continue;
            ll nextcost = 0;
            ll nextfreq = 0;
            if (i + 1 < n && arr[i + 1].first + 1 == cost)
            {
                nextcost = arr[i + 1].first;
                nextfreq = arr[i + 1].second;
                ll use1 = money / cost;
                // this if is wrong
                use1 = min(use1, freq);
                if ((use1 * cost) == money)
                {
                    res = money;
                    break;
                }
                else
                {
                    // there are 2 res first use req first and second
                    // second try to use 1 more of prev
                    ll firstres = cost * use1;
                    ll rem = money - firstres;
                    ll use2 = rem / nextcost;
                    use2 = min(use2, nextfreq);
                    ll secondres = use2 * nextcost;
                    ll finalfirst = firstres + secondres;
                    res = max(res, finalfirst);
                    ll finalsecond = 0;
                    use2++;
                    if (nextfreq > use2)
                    {

                        nextfreq -= use2;
                        ll second = use2 * nextcost;
                        finalsecond = firstres + second;
                        if (finalsecond >= money)
                            finalsecond -= money;
                        if (nextfreq >= finalsecond && use1 >= finalsecond)
                        {
                            res = money;
                            break;
                        }
                    }
                }
            }
            else
            {
                ll use1 = money / cost;
                use1 = min(use1, freq);
                ll currmoney = use1 * cost;

                res = max(res, currmoney);
            }
        }
        cout << res << endl;
    }
    return 0;
}
