#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we need to create array of any size pref min..

    and then the sum of that array == s..

    and each ele should be submask of m.

    one solution is i will do m,m,m,m,..

    now this will lead to sum going above s...

    so we will have to remove some bits..

    we just need to return the len not even the numbers..

    so we will have some rem = s - sum(m)

    now this rem i will try to remove

    this rem will have some bits

    if i remove those equivalend bits from array then it is

    possible..

    else not possible..

    3 = 1 + 1 + 1 || 2 + 1 ||

    we will see this rem also on bits basis..

    some power of 2 is set in rem

    we will have to unset that in array..

    so we will go on from msb of rem ...lsb

    and then for each set

    if this is set then i will take the right left bits

    of array ..

    and once i am good enough i will do ok = 1 and move to next bit..

    so some x bit would be enough to make it posssible ..


    now with that bit we will make it

    so we will req some x amount of that bit..

    now we will try to take some part of it and set it to other bigger set bits of m and then reduce the size of the array..






*/
int find(int bit, int freq)
{
    int n = (1 << bit);
    n *= freq;
    return n;
}
int solve(int s, int bit, int m)
{
    bool ok = 1;
    // first can we make s from this bit.
    // for that to be possible there shouldnt be any bit smaller than this bit in s.. 
    for(int next = bit - 1 ;next>=0;next--){
        if(s & (1<<next)){
            ok = false;
            break;
        }
    }
    if(ok == false) return -1;
    // now it is poss.
    // we will try to take bigger bits to make size small..
    int size = s / (1 << bit);
    // now we reduce this size..
    for(int next_bit = 60;next_bit >=bit;next_bit--){
        // this bit should be set in m as well..
        if(m & (1<<next_bit )){
            // now only we can use it..
            int 
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int s, m;
        cin >> s >> m;
        int temp = m;
        int curr = -1;
        for (int i = 60; i >= 0; i--)
        {
            if (temp & 1)
            {
                curr = solve(s, i, m);
                if (curr != -1)
                    break;
                temp = temp & ~(1LL << i);
            }
        }
        cout << curr << endl;
    }
    return 0;
}
