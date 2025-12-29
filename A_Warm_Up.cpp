#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so first we sort both the arrays and then if the current b[i] is lesser than a[i] , then it is impossible

    else if they are equal  then continue

    else :
        if the b[i] is not present in a set then also impossible

        else res++;


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("warm_up_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    int index = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = i;
        }
        vector<vector<int>> curr;
        for (int i = n - 1; i >= 0; i--)
        {
            curr.push_back({arr[i], b[i], i});
        }
        sort(curr.begin(), curr.end());
        set<int> st(arr.begin(), arr.end());
        vector<pair<int, int>> res;
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            int bi = curr[i][1];
            int ai = curr[i][0];
            int index = curr[i][2];
            if (bi < ai)
            {
                ok = false;
                break;
            }
            else if (ai == bi)
                continue;
            else
            {
                if (!st.count(bi))
                {
                    ok = false;
                    break;
                }
                else
                {
                    res.push_back({mp[bi] + 1, index + 1});
                }
            }
        }

        cout << "Case #" << index++ << ": ";
        if (ok == false)
            cout << -1 << endl;
        else
        {
            cout << res.size() << endl;
            for (auto a : res)
            {
                cout << a.first << " " << a.second << endl;
            }
        }
    }
    return 0;
}
