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
    for (ll i = 0; i < n; i++)
        s += '-';
    if (n & 1)
    {
        s[n / 2] = '=';
    }
    else
    {
        s[n / 2] = '=';
        s[(n - 1) / 2] = '=';
    }
    cout << s << endl;
    return 0;
}
