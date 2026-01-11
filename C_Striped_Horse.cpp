#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so i dont need to paint  all the squares..

    some x i  select ..

    when i do (i + x )% 2w

    the ans is from 0...2w-1

    all the ones that are from 0..w i need to consider

    that cost..

    so all the ci's that i dont want i  should

    make sure that rem is from w.. 2w - 1

    when i choose x as 0

    the ans for this is  0...2w-1,0...2w-1..

    and if i choose x as 1 : 1...2w-1,0,1...2w-1

    so all the nodes have an edge with someone..

    now from these i either take 0..w-1

    then i skip from w..2w-1 which is w..

    so i take w segment skip w segment take w segment

    skip w segment ...

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> prefix(n);
        for (int i = 0; i < n; i++)
        {
            prefix[i] = arr[i];
            if (i)
                prefix[i] += prefix[i - 1];
        }

        int res = LLONG_MAX;
        for (int skip_start = 0; skip_start <= min(w, n - 1); skip_start++)
        {
            int curr_res = 0;

            int curr = skip_start;

            if (skip_start == w)
            {
                curr_res += prefix[0];
            }

            // now take w skip w ..
            bool take = false;
            while (curr < n)
            {

                if (take == false)
                {
                    take = true;
                    curr += (w);
                }
                else
                {
                    take = false;
                    curr_res += (prefix[curr]);
                    int temp = prefix[curr];
                    if (curr - w >= 0)
                    {
                        curr_res -= prefix[curr - w];
                        temp -= prefix[curr - w];
                    }
                    curr += (w);
                }
            }

            if (take == true)
            {

                curr -= w;
                if (curr < n)
                {
                    curr_res += prefix[n - 1];
                    if (curr >= 0)
                    {
                        curr_res -= prefix[curr];
                    }
                }
            }

            res = min(res, curr_res);
        }
        cout << res << endl;
    }
    return 0;
}
