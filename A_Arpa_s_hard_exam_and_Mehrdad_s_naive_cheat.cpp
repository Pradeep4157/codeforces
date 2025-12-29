#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
        SAME METHOD WILL BE  USED HERE:
            SOLVE FUNCTION WILL GIVE THE WHOLE NUMBER WE JUST NEED TO RETURN RES%10:
        SOLVE(1378,B):
            INT RES=1;
            INT CURR=1378;
            WHILE(B):
                IF(B&1) RES=(RES*CURR):
                B/=2;
                CURR=(CURR*CURR):
            RETURN RES%10:


*/
const long long mod = (long long)(1e18 + 3); // or any other large prime
int solve(int a, int b)
{
    int res = 1;
    int curr = a % 10;
    while (b)
    {
        if (b & 1)
            res = (res * curr) % 10;
        b /= 2;
        curr = (curr * curr) % 10;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(1378LL, n) << endl;
    return 0;
}
