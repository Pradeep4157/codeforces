#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    p and q should have no common set bits..

    either it is a digit dp question or we can

    greedily say which bit is going to be set in

    p and which one is going to get set in q..

    or it is not going to be set in either one..

    now one of them is perfectly equal and the other one we are trying to make it equal..

    now there are somm bits that are left..

    to minimize this we can set some bits

    this we might do after trying to make equal..


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int diff = x + y;
        int p = 0, q = 0;
        int P = 0, Q = 0;
        int limit = (1 << 30);
        {
            // here we will first set all the bits of x..
            p = x;
            q = 0;
            for (int bit = 30; bit >= 0; bit--)
            {
                if (y & (1 << bit))
                {
                    // we should set this bit in q..
                    // but this bit should not be set in x ..
                    if (x & (1 << bit))
                    {
                        // then we will not set this bit..
                        // this is already used in x..
                    }
                    else
                    {
                        // now we can set..
                        q |= (1 << bit);
                    }
                }
            }
            int diff = abs(q - y);
            // we will try to minimize this diff...
            for (int bit = 30; bit >= 0; bit--)
            {
                // if this bit is not set in x then we can use it.
                if (x & (1 << bit))
                {
                }
                else
                {
                    // here we can..
                    int new_q = q | (1 << bit);
                    int new_diff = abs(y - new_q);
                    if (new_diff < diff)
                    {
                        q = new_q;
                        diff = new_diff;
                    }
                }
            }
            diff = abs(q - y);
            
            // we will try to minimize this diff...
            for (int bit = 0; bit < 31; bit++)
            {
                // if this bit is not set in x then we can use it.
                if (x & (1 << bit))
                {
                }
                else
                {
                    // here we can..
                    int new_q = q | (1 << bit);
                    int new_diff = abs(y - new_q);
                    if (new_diff < diff)
                    {
                        q = new_q;
                        diff = new_diff;
                    }
                }
            }
            // now here i assign P AND Q TO THESE ONLY..
            // now we try to unset some values from q.
            int CURR_DIFF = abs(q - y);

            for (int bit = 0; bit < 31; bit++)
            {
                if (q & (1 << bit))
                {
                    // we try to see if unset is better..
                    int new_q = (q ^ (1 << bit));
                    int neww_diff = abs(new_q - y);
                    if (neww_diff < CURR_DIFF)
                    {
                        CURR_DIFF = neww_diff;
                        q = new_q;
                    }
                }
            }
            P = p;
            Q = q;
        }

        {

            // now we will set q == y..
            q = y;
            p = 0;
            for (int bit = 0; bit < 31; bit++)
            {
                if (x & (1 << bit))
                {
                    // we should set this in p ..

                    // but this shouldnt be set in q..
                    if (q & (1 << bit))
                    {
                        // then we cant set ..
                    }
                    else
                    {
                        p |= (1 << bit);
                    }
                }
            }
            int diff = abs(p - x);
            for (int bit = 0; bit < 31; bit++)
            {
                // if this bit is not set in y then we can use it.
                if (y & (1 << bit))
                {
                }
                else
                {
                    // here we can..
                    int new_p = p | (1 << bit);
                    int new_diff = abs(new_p - x);
                    if (new_diff < diff)
                    {
                        diff = new_diff;
                        p = new_p;
                    }
                }
            }
            int CURR_DIFF = abs(p - x);
            // now here also  same..
            for (int bit = 0; bit < 31; bit++)
            {
                if (p & (1 << bit))
                {
                    // we might unset..
                    int new_p = (p ^ (1 << bit));
                    int neww_diff = abs(new_p - x);
                    if (neww_diff < CURR_DIFF)
                    {
                        CURR_DIFF = neww_diff;
                        p = new_p;
                    }
                }
            }

            int DIFF = abs(p - x) + abs(q - y);

            int first_diff = abs(P - x) + abs(Q - y);
            if (DIFF < first_diff)
            {
                P = p;
                Q = q;
            }
        }

        cout << P << " " << Q << endl;
    }
    return 0;
}
