#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
ll recursion(ll start, vector<ll> &arr, ll n)
{
    if (start == n - 1)
    {
        return arr[start];
    }
    return max(arr[start], recursion(start + 1, arr, n));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    cout << recursion(0, arr, n) << endl;
    return 0;
}
