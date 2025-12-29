#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
void recursion(ll n)
{
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    cout << n << " ";
    recursion(n - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    recursion(n);
    return 0;
}
