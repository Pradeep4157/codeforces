#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so pair sum of all the  adj numbers should be prime..

    it is cyclic..

    no arent supposed to prime..

    array size is small.

    one bf way is that i bf the  numbers for each pos..

    instead we can bf on the sum to be prime..

    there is an edge between all the adj elements..

    and we bf on these edge numbers..

    these numbers on the edges must be prime..

    but that also should be same because the no of edges are same

    as the no of elements..

    instead we can remember the first element and prev element..

    that should do.

    also we should know what all numbers are left..

    first lets imp the BF..

    first for that i need to know the primes that are req..

    it will be till n + n - 1...

    then i will have an map to keep  track of the eles that are left..

    and prev and first...

    still we also need to not count the cyclic shifts so mostly there

    would be n cyclic shifts for each permutation so maybe finalres/=n..







*/
int n;
vector<bool> isPrime;
void prime_maker(int n)
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
int res;
void find(int start, int first, int prev, vector<int> &mp)
{
    if (start == n)
    {
        // we are at the last pos..
        // and n >=2 so we have some def first..

        // and we will also have only 1 number left in mp..
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == false)
                continue;
            // this is the only ele..
            // the sum with prev and first should be prime.
            int first_number = i + first;
            int second_number = i + prev;
            if (isPrime[first_number] == false || isPrime[second_number] == false)
            {
            }
            else
                res++;
        }
        return;
    }
    // now we are at some intermediate index.
    // we will bf here..
    // if this is the first ele we dont care we just bf..
    if (start == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == 1)
            {

                mp[i] = 0;
                find(start + 1, i, i, mp);
                mp[i] = 1;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == 1)
            {
                // now it should be prime with prev as well.
                int sum = i + prev;
                if (isPrime[sum] == 1)
                {
                    // then it is valid..
                    mp[i] = false;
                    find(start + 1, first, i, mp);
                    mp[i] = 1;
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    isPrime.assign(n + n + 10, 1);
    prime_maker(n + n + 10);
    // for (int i = 1; i < isPrime.size(); i++)
    // {
    //     cout << i << ":" << isPrime[i] << " ";
    // }
    // cout << endl;
    res = 0;
    vector<int> mp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        mp[i]++;
    }
    find(1, n + 1, n + 1, mp);
    cout << res / n << endl;
    return 0;
}
