#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so i have q queries ..

    in each i can ask ele at some index..

    if that is 1 then it breaks..

    else if its zero then i can ask more..

    if q == n

    then i could literally keep

    asking every index from left..

    now it depends on how many q i have..

    one way is that from left

    i keep asking and then when i am finished..

    there are some indexes

    left now it can be from that i..n

    thats it ?

    size/2

    this is the safest dist..

    now if we keep using dist  - 1

    jumps

    if i want to keep

    x dist then

    i will have to

    keep jumping at x + 1 ..

    so req will be n / x + 1

    if that's >= q then poss else not ..

    this method is only wrong ?

    why ?

    if i want dist of x then i can only jump at max of x + 1..

    if i jump more than that then i wont know  or should i jump twice ?


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        q++;
        int res = n;
        int low = 0, high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int req = n / (mid + 1);
            if (req <= q)
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << res << endl;
    }
    return 0;
}
