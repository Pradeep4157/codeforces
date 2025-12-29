#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
        FOR N=2 ANS=8:
        7 8 77 88 78 87
        HOW DO WE FIND THESE NUMBERS:
            WE HAVE N DIGITS TO FILL WITH EITHER
            NOTHING OR 7 OR 8:
                SUBSETS GENERATION?
                7 OR 77 OR 777 OR 7777
                8 OR 88 OR 888 OR 8888

        THIS BELOW THING IS ONLY NEEDED:
            FOR EACH N WHAT ARE THE PERMUTATIONS
            THAT CAN BE GENERATED:
                FOR N=3:
                    777
                    778
                    787
                    788
                    888
                    878
                    887
                    877

                FOR N=2:
                    77
                    78
                    87
                    88

        FOR EACH N 2^N NUMBERS CAN BE CREATED:
            JUST ADD ALL OF THEM FROM 1->N

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        arr[i] = pow(2, i);
    }

    int res = accumulate(arr.begin(), arr.end(), 0LL);
    cout << res << endl;
    return 0;
}
