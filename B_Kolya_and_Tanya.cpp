#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
QUESTION SIMPLIFICATION:
    idk what a gnome is , there are 3n gnomes, each is numbered from 1->3

    gnome is some statue.


    so she selects 3 gnomes at once , if the sum != 6 she is satisfied.


OBSERVATIONS:

    the only way when tanya is not satisfied is when gnomes coins={1,2,3}
    or {1,3,2}
    or {2,1,3}
    or {2,3,1}
    or {3,1,2}
    or {3,2,1}

    and the last way is {2,2,2}



    in all the other ways the sum!=6

    what are the total ways?
        it is 27 because at every place we can fill any value from 1->3

        so at every step we need to do



    what if n==2 how many places and combinations can we make??

        _ , _ , _ , _ , _ , _


    so why is n==2 680
    because two ways are considered diff if there is some element that is different
    in both the arrays

    for every i<=n i can  put any of the 20 ways and for the remaining indexes
    i can fill them with whatever i want 3*(3n-3)

    there are going to be intersections because lets say i=0 i filled 1,2,2 at
    their resp indexes and for remaining i filled with 3*(3n-3)

    and when i go to i=1 then i cant fill i=0,0+n,0+2n with any of the 20 values
    i used before else it would be same array again,



    in the upfront cells you are going to fill them with any of the 1,2,3

    and for the remaining prev cells that were used for triplets in those you
    going to fill them with any of the values of the 7 possible values.

*/
const int mod = (int)(1e9 + 7);
int binpow(int base, int exp)
{
    if (exp == 0)
        return 1LL;
    if (exp & 1)
    {
        return (1LL * base * binpow(base, exp - 1)) % mod;
    }
    else
    {
        int temp = binpow(base, exp >>= 1);
        return (1LL * temp * temp) % mod;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int res = 0;
    int used = 0;
    int cellsremaining = 3 * n;
    int prevcells = 0;
    for (int i = 1; i <= n; i++)
    {
        cellsremaining -= 3;
        int curr = 20 * binpow(3, cellsremaining) % mod;
        curr = (curr * binpow(7, prevcells)) % mod;
        res = (res + curr) % mod;

        prevcells++;
    }
    cout << res << endl;
    return 0;
}
