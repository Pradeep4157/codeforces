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
    int t = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(m);
        for (int i = 0; i < m; i++)
            cin >> arr[i];

        int res = 0;
        while (n--)
        {
            int type, freq;
            cin >> type >> freq;

            int mini = min(freq, arr[type - 1]);
            res += mini;
            arr[type - 1] -= mini;
        }
        cout << res << endl;
    }
    return 0;
}
