#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


        if the rating >=x then she cant do anything ..

        now :
        1) we can always try to reduce her ratings , unless

        -d<0
        2) if 1 then res ++

        3) else if it is 2 if rating >=x continue

        else :
            if - d < 0 then do +d

            else -d
            res++
*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int r, x, d, n;
        cin >> r >> x >> d >> n;
        string s;
        cin >> s;
        int res = 0;
        for (auto a : s)
        {
            if (a == '1')
            {
                res++;

                if (r == 0)
                    r++;
                if (r < x - 1)
                {
                    continue;
                }
                else
                {
                    int dec = r - x + 1;
                    int maxdec = r;
                    dec = min(dec, maxdec);
                    if (dec > d)
                        dec = d;
                    r -= dec;
                }
            }
            else
            {
                if (r >= x)
                    continue; // we cant do anything
                else
                {
                    res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
