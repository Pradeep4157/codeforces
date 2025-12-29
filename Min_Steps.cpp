#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    it is impossible as well , when will it be impossible

    looks like a bs question where the equation is (x+ a*d)*(2^b)

    where i bs on a or b

    so we can brute force on b

    so we will

    can i bs on  a1 and a2 ?



    how do  i find what is a1


    should i bf on a1 && a2 is there a logical way to  reach there ?

    or is a2 just n % pow(2)


    11 - > (1)* 8 + 3

    but it can also be reached from some other path ?


    




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--)
    {
        int n, d;
        cin >> n >> d;
        int res = 0;
        while (n > 1)
        {
            if (n - d == 1)
            {
                n -= d;
                res++;
                continue;
            }
            if (n % 2 == 0)
            {
                res++;
                n /= 2;
            }
            else
            {
                n -= d;
                res++;
            }
        }
        if (n == 1)
            cout << res << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
