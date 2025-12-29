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
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        if (x == n)
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] = i;
            }
            for (auto a : arr)
            {
                cout << a << " ";
            }
            cout << endl;
            continue;
        }
        arr[n - 1] = x;
        int color = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (color == x)
                color++;
            arr[i] = color;
            color++;
        }
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
