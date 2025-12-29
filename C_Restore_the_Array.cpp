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
        n--;
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<int> res;
        res.push_back(b[0]);
        for (int i = 0; i < n - 1; i++)
        {
            res.push_back(min(b[i], b[i + 1]));
        }
        res.push_back(b[n - 1]);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
