#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we can binary search on how many left side we are going to fill..


    if there is only 1 side.. which means k is at some corner..

    then m days we have , if we choose to fill x side things then we need 2*x - 1 days..


    now what is the max left things that we can fill...

    it will be min of left , m + 1 / 2


    now i have some rem days i can  either start sending everything

    now only ..

    in the formula x + x - 1 to  fill x side things..

    first x is the amount of time req to collect the things...

    dist time is still same..

    if the amount of rem days < whatever i have collected till now

    then what's the point of collecting more..

    i wont be able to distribute them anyways ..







*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int left = k - 1;
        int right = n - k;
        int maxi = min((m + 1) / 2, left);
        int res = 1;
        for (int left_fill = 0; left_fill <= maxi; left_fill++)
        {
            int curr = 1;
            int left_collection_days = left_fill;
            int fill_days = max(0LL, left_collection_days - 1);

            int left_days = left_collection_days + fill_days;

            curr += left_fill;

            int rem_days = m - left_days;

            int now_have = fill_days;

            int can_give_right;
            // now i need to know  how many right can i give..
            if (rem_days < now_have)
            {
                // then just give in these days..
                can_give_right = rem_days;
            }
            else
            {
                // we have some more days for collections..

                int more_collect = rem_days - now_have;
                more_collect = (more_collect + 1) / 2;

                can_give_right = now_have + more_collect;
            }

            can_give_right = min(can_give_right, right);
            curr += can_give_right;

            res = max(res, curr);
        }
        cout << res << endl;
    }
    return 0;
}
