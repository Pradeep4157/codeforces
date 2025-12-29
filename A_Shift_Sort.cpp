#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        WE CAN RIGHT SHIFT OR LEFT SHIFT
    I CAN DO THIS FOR ONE OPERATION:
        100->001
        110->011

        1 ...1/0... 0 ...1/0...0

    FOR THESE WE DONT NEED TO DO ANYTING:
        011
        001

    THESE ALSO ONLY NEED 1 OPERATION:
        010
        101

    SO THE INITIAL IDEA WAS TO SWAP LAST SUBARRAY OF ZEROES WITH FIRST SUBARRAY OF
    ONES

    BUT THIS FAILS ON SOME TEST CASE

    THIS IS ONE OF THE EDGE CASES THAT I FOUND:01101010101

    THE MISTAKE WHICH I MADE WAS THAT FOR  110 I MADE A RIGHT SHIFT IF I DO THAT
    ALTHOUGH ZERO IS MOVED AHEAD OF 11 BUT 1 CAN STILL HAVE SOME ZEROES TO THE RIGHT
    (BECAUSE THE 2ND ONE WAS PUSHED TO THE RIGHT)

    WHAT IF IT WAS 01110101010101


    SO THE MIN(CZ,CO) ONLY WORKS WELL WHEN THERE IS NOTHING BETWEEN THESE
    TWO


    SO FOR A 1111..000.. TO CHANGE THIS:
        IF WE DO A RIGHT SHIFT:
            ->THEN WE NEED TO DO IT FREQ(ZERO) TIMES
            ->AND THOSE ZEROES NEED NOT BE CONSIDERED BY NEXT ONES
            ->BUT THESE ONES *IF THERE ARE ANY* STILL NEED TO BE CONSIDERED BY ZEROES BEFORE THIS
            ZERO SUBARRAY
        ELSE IF WE DO A LEFT SHIFT:
            ->THEN WE NEED TO DO FREQ(ONE) TIMES
            ->AND THOSE ONES NEED NOT BE CONSIDERED BY ZEROES BEFORE THIS ZERO
            SUBARRAY
            ->BUT THESE ZEROES *IF THERE ARE ANY* STILL NEED TO BE CONSIDERED
            BY ONES AFTER THAT


        SO ANS FOR ANY QUERY IS:
            EITHER LEFT SHIFT:
                ANS=MIN(PREFIX OF ONES BEFORE THIS,CURR ZEROES)
            ELSE(RIGHT SHIFT):
                ANS=MIN(ONES,SUFFIX OF ZEROES AFTER THIS)


        INSTEAD OF ALL THIS:
            WE KNOW THAT THE STRING SHOULD BE THIS:000..1111
            SO IF WE PLACE ZEROES AT THEIR PLACES THEN ONES WILL AUTOMATICALLY BE AT
            THEIR OWN PLACES?



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
        string s;
        cin >> s;
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (sorted[i] == '1')
                break;
            if (s[i] == '0')
                continue;
            else
                res++;
        }
        cout << res << endl;
    }
    return 0;
}
