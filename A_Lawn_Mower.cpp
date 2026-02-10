#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int amount = n / (k);
        int total = amount * (k - 1);
        int rem = n % k;
        total += rem;
        cout << total << endl;
    }
    return 0;
}
