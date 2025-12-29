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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        if (arr[n - 1] - arr[0] > (k + 1))
        {
            cout << "Jerry" << endl;
            continue;
        }
        int maxele = arr[n - 1];
        if ((arr[n - 1] - arr[0]) > k)
        {
            int count = 0;
            for (auto a : arr)
                if (a == maxele)
                    count++;
            if (count > 1)
            {
                cout << "Jerry" << endl;
                continue;
            }
        }
        int ans = 0;
        // remove the minimum
        int sum = accumulate(arr.begin(), arr.end(), 0LL);
        if (sum % 2 == 0)
        {
            cout << "Jerry" << endl;
        }
        else
            cout << "Tom" << endl;
    }
    return 0;
}
