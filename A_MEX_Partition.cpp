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
        {
            cin >> arr[i];
        }
        int mex = 0;
        set<int> st(arr.begin(), arr.end());

        for (int i = 0; i < 120; i++)
        {
            if (!st.count(i))
            {
                mex = i;
                break;
            }
        }
        cout << mex << endl;
    }
    return 0;
}
