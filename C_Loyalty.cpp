#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    we want to buy n items..

    so the shop items cost at max X

    my loyalty level is s/x .. s is the cost of items

    i have purchased..

    when i buy an item.. of price p

        && if my loyalty level inc.. then i earn those p points..


    i want to maximize these p that i can get ..

    so for all the coins >= X i will get all of them ..

        now for all these remaining coins..

            i need to  arrange them somehow that ..

            so only some of the coins can be used..

                that is number = sum of these + (extra from higher coins)/ x  , now for these

                i will all these number max coins..


    now how do i arrange ..

        first obv i will place all >=x coins ...


        now for the remaining coins there are useless coins && useful whenever the sum is going to  exceed factor of x i will place a useful

        coin else i will place useless ..

        how do i know current sum / x ! = (current sum + useless coin) / x then i will place ..

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);

        vector<int> need, noneed;
        int sum = 0;
        int ans = 0;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] >= x)
            {
                res.push_back(arr[i]);
                sum += arr[i];
                ans += arr[i];
            }
            else
                need.push_back(arr[i]);
        }
        sort(need.begin(), need.end());
        int remsum = accumulate(need.begin(), need.end(), 0LL);
        int rem = accumulate(res.begin(), res.end(), 0LL) % x;
        remsum += rem; // leftover of higher ups..
        int coins = remsum / x;
        vector<int> useful;
        while (coins)
        {
            // moving useful coins..
            int last = need.back();
            need.pop_back();
            useful.push_back(last);
            coins--;
        }

        // now useless is need array
        int i = 0;
        while (i < need.size())
        {
            int curruseless = need[i];
            if (((sum + curruseless) / x) != (sum / x))
            {
                // then i will use that useful coin..
                if (!useful.empty())
                {
                    int last = useful.back();
                    useful.pop_back();
                    res.push_back(last);
                    ans += last;
                    sum += last;
                }
                else
                {
                    cout << "ahahha" << endl;
                }
            }
            else
            {
                // i will use the useless coin..
                sum += curruseless;
                res.push_back(curruseless);
                i++;
            }
        }
        if (!useful.empty())
        {
            for (auto a : useful)
            {
                res.push_back(a);
                ans += a;
            }
        }
        cout << ans << endl;
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
