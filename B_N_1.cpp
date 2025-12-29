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

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool ok = false;
    int sum = accumulate(arr.begin(), arr.end(), 0LL);
    for (int i = 0; i < n; i++)
    {
        int rem = sum - arr[i];
        if (rem == m)
            ok = 1;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
