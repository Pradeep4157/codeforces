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

        int n, m;
        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        vector<int> arr(n + m);
        for (int i = 0; i < n + m; i++)
            cin >> arr[i];
        cout << (n + m) << endl;
    }
    return 0;
}
