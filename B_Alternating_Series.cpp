#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
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
        bool neg = true;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                arr[i] = -1;
            else
                arr[i] = 3;
        }
        if (n % 2 == 0)
        {
            arr[n - 1] = 2;
        }
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
