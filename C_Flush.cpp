#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    vector<int> prefix(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        prefix[i] = sum;
    }
    while (q--)
    {
        int b;
        cin >> b;
        auto it = lower_bound(arr.begin(), arr.end(), b);
        if (it == arr.end())
        {
            cout << -1 << endl;
            continue;
        }
        int index = it - arr.begin();
        int res = 0;
        int useless = 0;
        if (index > 0)
            useless = prefix[index - 1];
        res += useless;
        int rem = (n - index);
        res += ((b - 1) * rem);
        res++;
        cout << res << endl;
    }

    return 0;
}
