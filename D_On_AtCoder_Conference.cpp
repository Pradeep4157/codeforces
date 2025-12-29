#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so maybe we start at index i only :

        now for every i from 0 .. m - 1 although m can range till 1e12 we dont

        need to find till that only till n would be enough and the remaining

        would be same only ..

        for every i .. :
            if there is a j >= i we can find prefix[i-1] if it exists

            and find lower bound of prefix[i-1] + c .

            else we find lower_bound of (c - suffix[i] )

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> prefix(n), suffix(n);
    for (int i = 0; i < n; i++)
    {
        prefix[i] = arr[i];
        if (i)
            prefix[i] += prefix[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        suffix[i] = arr[i];
        if (i < n - 1)
            suffix[i] += suffix[i + 1];
    }
    // now we find for each till
    vector<int> preprocess(n);
    for (int i = 0; i < n; i++)
    {
        // if suffix is not enough ?
        int after = suffix[i];
        if (after < c)
        {
            // then we need to add some from start as well
            int fromfirst = c - after;
            auto it = lower_bound(prefix.begin(), prefix.end(), fromfirst);
            int extra = *it;
            int total = extra + after;
            preprocess[i] = total;
        }
        else
        {
            // now till some j >=i it should be enough
            int before = 0;
            if (i)
                before += prefix[i - 1];
            auto it = lower_bound(prefix.begin(), prefix.end(), before + c);
            int total = *it - before;
            preprocess[i] = total;
        }
    }
    // now we have everything

    // first total rounds these will cost total sum of preprocess
    int first = m / n;
    int res = 0;
    int all = accumulate(preprocess.begin(), preprocess.end(), 0LL);
    res += (first * all);
    int rem = m % n;
    for (int i = 0; i < rem; i++)
    {
        cout << preprocess[i] << endl;
        res += preprocess[i];
    }
    cout << res << endl;
    return 0;
}
