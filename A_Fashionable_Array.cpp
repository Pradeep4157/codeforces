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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        if ((arr[0] + arr[n - 1]) % 2 == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int first = 0;
        int j = n - 1;
        while (j >= 0 && (arr[0] + arr[j]) & 1)
        {
            j--;
            first++;
        }
        int second = 0;
        int i = 0;
        j = n - 1;
        while (i <= j && arr[i] + arr[j] & 1)
        {
            i++;
            second++;
        }
        cout << min(first, second) << endl;
    }
    return 0;
}
