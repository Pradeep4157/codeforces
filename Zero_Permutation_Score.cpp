#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so all are zeroes initially..

    score min..

    inc when ai == ai  + 1 && ai == 0 ..


    so we will apply on all odd indexes..

    so that it affects

    after every op..

    n -= 2

    and res+=max(0,n-1)



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
        while (n)
        {
            n -= 2;
            if (n <= 1)
                break;
            res += max(0LL, n - 1);
        }
        cout << res << endl;
    }
    return 0;
}
