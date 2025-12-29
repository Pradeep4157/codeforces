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
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        int i = 0;
        while (i + 1 < n)
        {
            if (i + 1 < n)
            {
                swap(arr[i], arr[i + 1]);
            }
            i += 2;
        }

        if (i < n)
            swap(arr[i], arr[i - 1]);
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
