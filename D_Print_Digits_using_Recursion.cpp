#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
void recursion(string N)
{
    if (N.size() == 1)
    {
        cout << N[0] << endl;
        return;
    }
    cout << N[0] << " ";
    recursion(N.substr(1));
}
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
        string N = to_string(n);
        recursion(N);
    }
    return 0;
}
