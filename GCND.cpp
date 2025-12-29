#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if a && b are same then gncd will just be a

    non divisible number of a || b

    one method is we can take biggest prime

    that is lesser than or equal  to 2 number in the

    array .

    ok so for any two number a && b

    where b > a there gncd will be either b - 1 or

    b - 2 because if b - 1 is divisible by a then

    b - 2 is the answer

    so i will always match all the numbers with

    arr[n - 1] ?


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        int last = arr[n - 1];
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int gncd = last;
            while (((arr[i] % gncd) == 0) || ((last % gncd) == 0))
            {
                gncd--;
            }
            res = max(res, gncd);
        }
        cout << res << endl;
    }
    return 0;
}
