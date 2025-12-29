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
        vector<int> res(n);
        int newnumber = 1;
        res[0] = newnumber;
        newnumber++;
        for (int i = 1; i < n; i++)
        {
            int diff = arr[i] - arr[i - 1];
            if (diff > i)
            {
                res[i] = newnumber;
                newnumber++;
            }
            else
            {
                res[i] = res[i - diff];
            }
        }
        for (auto a : res)
            cout << a << ' ';
        cout << endl;
    }
    return 0;
}
