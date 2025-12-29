#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


        A^B:
            IF WE CALCULATE MANUALLY WHILE B:
                B--:
                RES=RES*A;
            B<=1E9->TLE:
            THERE IS SOME METHOD TO CALCULATE POWER IN LOGB(B IS THE POWER).
            THE METHOD WAS SOMETHING LIKE THIS.
            SOLVE():
                INT RES=1:
                INT CURR=A:
                    WHILE(B):
                        IF(B&1) RES=(RES*CURR)
                        B/=2:
                        CURR=(CURR*CURR)
                RETURN RES:



*/
const int mod = (int)(1e9 + 7);
int solve(int a, int b)
{
    int res = 1;
    int curr = a;
    while (b)
    {
        if (b & 1)
            res = (res * curr) % mod;
        b /= 2;
        curr = (curr * curr) % mod;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
