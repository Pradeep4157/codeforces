#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
void recursion(vector<ll> &arr, ll n)
{
    if (n == 0)
    {
        cout << arr[n];
        return;
    }
    if (n % 2 == 0)
    {
        cout << arr[n] << " ";
    }
    recursion(arr, n - 1);
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
    recursion(arr, n - 1);
    return 0;
}
