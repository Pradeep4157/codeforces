#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    what are the scenarios ?


    ...ai .... bi ....

    OR

    ....bi ... ai ...


    in the first case :

    i dont need to maximize the ans at

    every step..

    only after the last my ans should be max..

    maybe for every val apart from last val

    it is just the one which gives bigger

    abs val..

    at the end whichever gives bigger val we will return..






*/
signed main()
{
    /*

    if ai , k = k - ai

    else if bi , k = bi -k..




    */
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int res = 0;
        int n;
        cin >> n;
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> mini(n), maxi(n);
        mini[0] = min(-arr[0], b[0]);
        maxi[0] = max(-arr[0], b[0]);
        for (int i = 1; i < n; i++)
        {
            mini[i] = min({mini[i - 1] - arr[i], maxi[i - 1] - arr[i], b[i] - mini[i - 1], b[i] - maxi[i - 1]});
            maxi[i] = max({mini[i - 1] - arr[i], maxi[i - 1] - arr[i], b[i] - mini[i - 1], b[i] - maxi[i - 1]});
        }
        cout << maxi[n - 1] << endl;
    }
    return 0;
}
