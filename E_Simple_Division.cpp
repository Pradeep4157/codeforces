#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we need to return n / m

    so li digits of ci

    maybe keep adding the current number

    from left side

    and then do res = (res*10) + dig

    and after division

    add the above thing to the res..

    also maybe at all steps do n%=mod

    and at the begining do m%= mod


    but  li <= 1e9 so we cannot make string

    as well...

    after a certain point

    the remainders just starts

    repeating..

    so if we find that this rem

    is already found before..

    then the last rem after all this

    is just going to be :

    the the rem at index of

    digits_left %= size of the repeation

    and then move to the next..

    the size is the index where it is found..

    that can be done using map..







*/
const int mod = 10007;

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

int mod_inverse(int a)
{
    return power(a, mod - 2);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, m;
    cin >> k >> m;
    int numerator = 0;
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        int ci, li;
        cin >> ci >> li;
        mp.clear();
        int size = 0;

        while (li--)
        {

            size++;
            numerator = (numerator * 10) + ci;
            numerator %= mod;

            if (mp.count(numerator))
                break;
            mp[numerator] = size;
        }

        if (li > 0)
        {
            int start = mp[numerator];
            size -= start;
            int index = (li % size) + start;
            numerator = mp[index];
        }
    }
    cout << (316227766 % mod) << endl;
    int n = numerator;
    int res = (n % mod) * mod_inverse(m % mod) % mod;
    int next = ((n % m) * mod_inverse(m)) % mod;
    res += next;
    cout << next << endl;
    cout << res << endl;
    return 0;
}
