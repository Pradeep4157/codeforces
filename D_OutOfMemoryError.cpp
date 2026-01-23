#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    every element resets not only that one..

    when an ele exceeds h all the prev operations

    on all the  elements are removed..

    i can keep count of vanishes on each ele..

    now when i am on some ele if the addition

    exceeds h then inc vanishes..

    and now first reset the value of this ele..

    and then for  all the  rem ele..

    if the vanishes of that ele < curr_vanish

    then make vanish count of that arr[i] to

    current vanish and add extra h



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> res = arr;
        vector<int> vanish_count(n, 0);
        int curr_vanish = 0;
        while (m--)
        {
            int b, c;
            cin >> b >> c;
            b--;
            if (vanish_count[b] < curr_vanish)
            {
                vanish_count[b] = curr_vanish;
                res[b] = arr[b];
            }
            // now do the inc operator..
            if (res[b] + c > h)
            {
                curr_vanish++;
                // reset..
                res[b] = arr[b];
                vanish_count[b] = curr_vanish;
            }
            else
            {
                // its safe..
                res[b] += c;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (vanish_count[i] < curr_vanish)
            {
                // reset them as well..
                res[i] = arr[i];
            }
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
