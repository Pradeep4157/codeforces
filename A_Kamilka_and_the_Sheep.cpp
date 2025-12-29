#include <bits/stdc++.h>
#define int long long
using namespace std;
int maxGCDwithMinD(int a, int b)
{
    if (a == b)
        return a;

    int g = abs(a - b);
    int rem = a % g;
    int d = (rem == 0) ? 0 : g - rem;

    return __gcd(a + d, b + d);
}
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
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int res = 1;

        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int currgcd = maxGCDwithMinD(arr[j], arr[k]);
                res = max(currgcd, res);
            }
        }

        cout << res << endl;
    }
    return 0;
}
