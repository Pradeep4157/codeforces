#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    o...r is same as l..0

    so count that and double and return..

    count 1..r double that and then count for 0..

    for every r.. .

    range is d...u

    len where this is big is from -r...r

    in this range r >= u / d..

    if r is even then res += 2*r..

    else nothing..

    now beyond this range..

    r + 1...u

    r - 1...d

    they are bigger..

    5...6

    range/2

    if start is even then do res++



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    int res = 0;
    for (int i = max(l, 0ll); i <= r; i++)
    {
        // for this col range is from d...l
        // -r...r we will add if even..
        int curr = 0;
        if (i % 2 == 0)
        {
            // for upper..
            curr += min({i, u + 1, 0LL}); // if u is neg then why add that..
            // if d is poss..
            curr -= max(0LL, d);
            // now below 0..
            // take upto d... and remove the u part..
            int below = min(i, d - 1);
            below = min(0LL, below);
            curr += abs(below);
            // removing the u part..
            below = 0;
            below = min(i, u + 1);
            below = min(0LL, below);
            curr -= below;
            curr = max(curr, 0ll);
        }
        res += curr;
        // now beyond r..
        // for above ..
        int lower = max(d, i + 1);
        int above = max(0LL, u - lower + 1);
        res += (above / 2);
        if (lower % 2 == 0 && above)
            res++;
        if (d < 0)
        {
            int below = abs(d);
            int lower = min({-i - 1, u, 0LL});
            below = max(0LL, abs(below - lower + 1));
            if (below)
            {
                res += (below / 2);
                if (lower % 2 == 0)
                    res++;
            }
        }
    }
    for (int I = min(r, -1LL); I <= l; I--)
    {
        int i = abs(I);
        cout << i << endl;
        // for this col range is from d...l
        // -r...r we will add if even..
        int curr = 0;
        if (i % 2 == 0)
        {
            // for upper..
            curr += min({i, u + 1, 0LL}); // if u is neg then why add that..
            // if d is poss..
            curr -= max(0LL, d);
            // now below 0..
            // take upto d... and remove the u part..
            int below = min(i, d - 1);
            below = min(0LL, below);
            curr += abs(below);
            // removing the u part..
            below = 0;
            below = min(i, u + 1);
            below = min(0LL, below);
            curr -= below;
            curr = max(curr, 0ll);
        }
        res += curr;
        // now beyond r..
        // for above ..
        int lower = max(d, i + 1);
        int above = max(0LL, u - lower + 1);
        res += (above / 2);
        if (lower % 2 == 0 && above)
            res++;
        if (d < 0)
        {
            int below = abs(d);
            int lower = min({-i - 1, u, 0LL});
            below = max(0LL, abs(below - lower + 1));
            if (below)
            {
                res += (below / 2);
                if (lower % 2 == 0)
                    res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
