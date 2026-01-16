#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so each part stores s..

    and he flips every k minutes..

    so if k == s then :

        at every flip k sand move in other side..

        last = (m / k )* s is the time when he last flipped

        last<=m
            and rem = max(0,s - (m - last))


    else if k > s :

        then here it pours all sand in other side wait for

        some time and then flips..

        so at any kth point it starts from 0...s

        last = (m/k)*s this is the last time when he flipped..

        rem = max(rem ,s - ( m - last) )

    else k < s :

        here only k things move from one part to another..

        at even turn all sand is in one part

        else if odd then k part is in other part and s - k part

        is in other part..

        now last = (m/k)*s

        if (m / k) is even then whole s things will move to the other

        side

        else only s - k things will move to the other side..

        we have this rem only its either s - k or k

        so rem = max(0,- m +last+ whatever)..





*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int s, k, m;
        cin >> s >> k >> m;
        if (k >= s)
        {
            // then the same thing happens..
            int last = (m / k) * k;

            int res = max(0LL, s - (m - last));
            cout << res << endl;
        }
        else
        {
            int rem = s;
            int last = (m / k) * k;
            if ((m / k) & 1)
            {
                // that means last flip was odd so only k will move..
                rem = k;
            }

            int res = max(0LL, rem - (m - last));
            cout << res << endl;
        }
    }
    return 0;
}
