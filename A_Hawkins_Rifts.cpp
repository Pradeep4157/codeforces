#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so if i fix at i,

    then there is only one j that

    is stable remaining should be unstable..

    so if bf on this i ..

    j can be from i + 1.. n

    no of ways are ...

    for every i :

        there are n - i numbers that we

        can select..

    and then for j :

    maybe because of mod we dont need to

    find the whole factorial..


    mod of 69696 is zero ..

    all the numbers are from 0..69696..

    so we multiple 1...69696 1...69696 1...69696

    and then there are some rem..

    so first we remove these 69696..




*/

const int mod = 69696;

int factorial_mod(int n)
{
    int result = 1;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        result = ((result % mod) * (i % mod)) % mod;
    }
    return result;
}

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

        if (n > mod)
            cout << 0 << endl;
        else
            cout << factorial_mod(n) << endl;
    }
    return 0;
}
