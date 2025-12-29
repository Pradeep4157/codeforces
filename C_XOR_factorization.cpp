#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    k numbers are given..

    all are from 0..n

    xor factorization of n is a1^a2^...ak == n ..

    sum should be maximized..

    some xorr def existss..

    n 0 ....

    now we need to maximize this..

    first trying to get max out of set bits of n..

    some set bits are there.

    if k is odd then i can set all these set bits of n in all

    the numbers..

    else if k is even then i can set all these set bits in k - 1 numbers and in the last number i will have to unset this bit..


    now for the unset bits..

    if k is even then i can set all these unset bits of n to all the k numbers..

    else if k is odd then i can set all these unset bits of all the  k - 1 numbers..

    now this is def answer

    but all a[i] should be <=n ..

    so i will start from the msb of n till lsb of n..

    for every bit

    i will check how many numbers are ok with me setting this bit

    that number should just be even / odd...

    lets say for set bit of n ..

    when k is odd i could set all the bits..

    but i can set only x numbers if x is even then remove some index

    and if x is odd then set all these bits..

    in my code the err can be :

    i) there are more bits that i can set..

    ii)  maybe the total xorr != n .


    mostly it is that becuase i am more focused to inc the number no number is left..

    in my code i am not being able to do anything about the unset bits of n..

    they are left unset in all the numbers





*/
vector<int> make_bits(int n)
{
    vector<int> res;
    while (n)
    {
        if (n & 1)
            res.push_back(1);
        else
            res.push_back(0);
        n >>= 1;
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(k, 0);
        int tempn = n;
        vector<int> bits = make_bits(n);
        int size = bits.size();
        for (int bit = size - 1; bit >= 0; bit--)
        {
            priority_queue<pair<int, int>> allowed;
            for (int i = 0; i < k; i++)
            {
                int new_number = (arr[i] | (1 << bit));
                if (new_number <= n)
                    allowed.push({new_number, i});
            }
            // now we have the participants that can allow this bit to be set..
            // now we will see whom all can we allow
            int size = allowed.size();

            if (bits[bit] == 1)
            {

                // we again just want odd numbers..
                if (size > 0 && (size % 2) == 0)
                {
                    allowed.pop();
                }
            }
            else
            {
                // bit should be unset at the end..
                // so even set bits should be there.
                if (size > 0 && (size & 1))
                {

                    // we only want even bits..
                    allowed.pop();
                }
            }
            // now we have all the correct parti..
            while (!allowed.empty())
            {
                int a = allowed.top().second;
                allowed.pop();
                arr[a] |= (1 << bit);
            }
        }
        sort(arr.begin(), arr.end());
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
