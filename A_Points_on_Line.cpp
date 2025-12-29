#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(arr.begin(), arr.end(), arr[i] + d);
        it--;
        int index = it - arr.begin();
        int numbers = index - i;
        // cout << index << ":" << i << endl;
        int curr = (numbers * (numbers - 1)) / 2;
        // cout << curr << endl;
        res += curr;
    }
    cout << res << endl;
}
