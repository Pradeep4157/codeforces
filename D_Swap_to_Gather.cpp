#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> index;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            index.push_back(i);
        }
    }

    ll size = index.size();
    if (size == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    ll median_idx = size / 2;            
    ll median_value = index[median_idx]; 
    ll swaps = 0;
    for (ll i = 0; i < size; i++)
    {
        swaps += abs(index[i] - (median_value - median_idx + i));
    }

    cout << swaps << endl;
    return 0;
}
