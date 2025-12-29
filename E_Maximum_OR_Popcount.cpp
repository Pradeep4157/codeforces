#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    here we will start from the lsb and keep adding bits until we run out of bi

    for each bit at max we can set:
        n-set bits at that position


        what is the operation to change per bit:
            2^ bit is the operation req to change one out of them .

            what is the max i can  improve:
            if(bi<per cost) then just break:
                int first=bi/per cost
                then cost=percost*first;
                bi-=cost;
                res+=(first+already bits set)


        FUCK !! 
        
        we had to maximize a single bit 

        for a bit we already have the set bits to set some other bits we need to set 
*/
int binpow(int base, int exp)
{
    if (exp == 0)
        return 1LL;
    if (exp & 1)
    {
        return base * binpow(base, exp - 1);
    }
    else
    {
        int temp = binpow(base, exp >> 1);
        return temp * temp;
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> bitset(32);
        for (auto a : arr)
        {
            int ele = a;
            int bit = 0;
            while (ele)
            {
                if (ele & 1)
                    bitset[bit]++;
                ele >>= 1;
                bit++;
            }
        }
        // now i have all the  bits

        while (k--)
        {
            int bi;
            cin >> bi;
            int res = 0;
            for (int i = 0; i < 3; i++)
            {

                int currset = bitset[i];
                int rem = n - currset;

                int percost = binpow(2, i);

                int first = bi / percost;
                first = min(first, rem);
                int cost = first * percost;
                bi -= cost;
                cout << first << ":" << bitset[i] << endl;
                res += (first + bitset[i]);
            }
            cout << res << endl;
        }
    }
    return 0;
}
