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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        bool odd = false, even = false;
        for (auto a : arr)
        {
            if (a & 1)
                odd = 1;
            if (a % 2 == 0)
                even = 1;
        }
        if (even && odd)
        {
            sort(arr.begin(), arr.end());
        }
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
