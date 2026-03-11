#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    i take two ele

    add max of that to res and

    then insert & of that if its not

    in the set ..

    does it even matter ?

    maybe inserting it again i might use it

    again..

    so first i will take max and

    0,1,2,3,4
    0,1,2,3
    4 + 1 + 2 + 3
    {0,1,2}
    2 + {0,1}

{0,1,2,3,4}

2 + 4
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
        int res = 0;
        for (int i = 2; i <= n; i += 2)
            res += i;
        cout << res << endl;
    }
    return 0;
}
