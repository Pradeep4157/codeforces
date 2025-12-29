#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        int ele = arr[n / 2];
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += abs(arr[i] - ele);
        }
        cout << res << endl;
    }
    return 0;
}
