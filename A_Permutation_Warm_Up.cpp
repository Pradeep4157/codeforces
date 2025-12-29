#include <bits/stdc++.h>
#define int long long
using namespace std;

int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int maxdiff = 0;
        for (int i = 1; i <= n; i++)
        {
            int mirror = n - i + 1;

            maxdiff += abs(mirror - i);
        }
        cout << maxdiff / 2 + 1 << endl;
    }
    return 0;
}
