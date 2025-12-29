#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    in this array:
        0 3 -2 5 -4 -4
        these are valid:
            0,3,-2,-4,-4


            it has something to do with consective days:
                all k=1 are possible so res is still 15

                for k=2 -2,-4 is not possible because they arent consecutive so res=14


                so maybe in short we have to consider 0,3,-2  this as separate and
                -4,-4 this as separate that's why answer comes out to be 9



            what are the ways that i can select any 3 ,4,5:

    maybe it is better to have count sizes so that i can just count those


*/
int factorial(int n)
{
    if (n == 0)
        return 0;
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> arr(n);
        int count = 0;
        vector<int> cd;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] <= q)
            {
                count++;
            }
            else
            {
                cd.push_back(count);
                count = 0;
            }
        }
        cd.push_back(count);

        int res = 0;
        for (auto a : cd)
        {
            if (a >= k)
            {
                res += (long long)(a - k + 1) * (a - k + 2) / 2;
            }
        }
        cout << res << endl;
    }
    return 0;
}
