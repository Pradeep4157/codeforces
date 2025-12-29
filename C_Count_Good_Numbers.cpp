#include <bits/stdc++.h>
#define int long long
using namespace std;
int count(int n)
{

    return (n - n / 2 - n / 3 - n / 5 - n / 7 + n / 6 + n / 10 + n / 14 + n / 15 + n / 21 + n / 35 - n / 42 - n / 30 - n / 70 - n / 105 + n / 210);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        int l, r;
        cin >> l >> r;
        cout << count(r) - count(l - 1) << endl;
    }
    return 0;
}
