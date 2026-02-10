#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so we can only trasfer x units..

    and y will be sent..

    lets say i have some arr[i] where they are divisible by x..

    then i can transfer all to some other..

    else :
        transfer whatever's possible and then..

        some rem is left..

        we will have to send
        \

    we have to empty n - 1 things and


    so divisible i remove..

    for rem things..

    i have some rem left..

    to remove this i need to
*/

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int can_take = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i] / x;
            int curr_take = curr * y;
            can_take += curr_take;
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i] / x;
            int curr_take = curr * y;

            int rem_take = can_take - curr_take;
            res = max(res, rem_take + arr[i]);
        }
        cout << res << endl;
    }
    return 0;
}
