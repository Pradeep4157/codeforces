#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
/*
        OBSERVATIONS:




*/
void solve()
{
    ll n, m, l;
    cin >> n >> m >> l;
    vector<pair<ll, ll>> hurdles(n);
    vector<pair<ll, ll>> powerups(m);
    int total = 0;
    for (auto &it : hurdles)
        cin >> it.first >> it.second;
    for (auto &it : powerups)
        cin >> it.first >> it.second;
    ll ind = 0, curr_power = 1;
    priority_queue<ll> boosts;
    for (int i = 0; i < n; i++)
    {
        ll dis_cover = hurdles[i].second - hurdles[i].first + 2;

        while (ind < m && powerups[ind].first < hurdles[i].first)
        {
            boosts.push(powerups[ind].second);
            ind++;
        }
        while (curr_power < dis_cover && !boosts.empty())
        {
            curr_power += boosts.top();
            boosts.pop();
            total++;
        }
        if (boosts.empty() && curr_power < dis_cover)
        {
            cout << "-1\n";
            return;
        }
    }

    cout << total << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
