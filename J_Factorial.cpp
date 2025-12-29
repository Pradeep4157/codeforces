#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
ll recursion(ll n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * recursion(n - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << recursion(n) << endl;
    return 0;
}
