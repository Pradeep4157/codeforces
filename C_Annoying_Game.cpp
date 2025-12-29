#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        two arrays...

        k turns..

        choose index i ..

        either ai = ai + bi

        or

        ai = ai - bi ..

        both perf op on a only..

        score = max non empty subarray sum..

        alice wants to max.. bob wants to  min..

        one thing is sure that alice will try to

        maximize the element from which max

        res is ob..  or will he try to upgrade the

        min ele..

        bob will maybe just nullify the effect of alice

        yaa mostly bob should do that

        if he tries to minimize some other ele

        alice will again maximize this ele..

        so if k is even its just kadane..

        else

        we will select one ele which gives  the best res..

        and do that op..

        can be bf ?

        either i upgrade it or skip it ..

        if  i upgrade it ..

        now for the else part..

            if i upgrade it ..

            it will be prefix[i - 1] + upgrade + suffix [i + 1]..

            prefix creation ..

            if prefix[i] = arr[i] + prefix[i - 1]

            if prefix[i ] < 0 :
                prefix[i] = 0

            same for suffix..





*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
            cin >> b[i];
        if (k % 2 == 0)
        {
            int maxi = arr[0];
            int curr = 0;
            for (int i = 0; i < n; i++)
            {
                curr += arr[i];
                maxi = max(maxi, curr);
                if (curr < 0)
                    curr = 0;
            }
            cout << maxi << endl;
            continue;
        }
        // now we maybe bf..
        vector<int> prefix(n, 0), suffix(n, 0);
        // prefix creation..
        prefix[0] = max(arr[0], 0LL);
        for (int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];

            prefix[i] = max(prefix[i], 0LL);

            prefix[i] = max(prefix[i], arr[i]);
        }
        //  now suffix.
        suffix[n - 1] = max(arr[n - 1], 0LL);
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = arr[i] + suffix[i + 1];
            suffix[i] = max(0LL, suffix[i]);
            suffix[i] = max(suffix[i], arr[i]);
        }
        // now bf ..
        int res = LLONG_MIN;

        for (int i = 0; i < n; i++)
        {
            // now we will bf..

            // now we will upgrade this..

            int curr = arr[i];
            curr += b[i];

            res = max(res, curr);
            //  maybe we want to  join with prefix..
            if (i)
                res = max(res, curr + prefix[i - 1]);

            // maybe we just want to join with suffix..
            if (i < n - 1)
                res = max(res, curr + suffix[i + 1]);

            // maybe we want to join with both of them..
            if (i > 0 && i < n - 1)
                res = max(res, curr + prefix[i - 1] + suffix[i + 1]);
        }
        cout << res << endl;
    }
    return 0;
}
