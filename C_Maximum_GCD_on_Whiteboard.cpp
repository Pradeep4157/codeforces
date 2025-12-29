#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    the k that we have can be used to erase any k elements in the array

    else i add x1,x3 and erase x , this can be performed any times

    ok so we need to maximize the gcd of the array

    so which operation is better lets say we have x == n

    do we use split in this case ?

    5 7 8  x == 3 one obv answer is 8 can i still improve it ?

    also these splits will be used on the elements that i dont

    want in my final array maybe because they reduce gcd to 1

    let say i have 9,14 gcd == 1 now i will split 9 to  some factor

    of 14 such that that factor can be split this way :

        factor(x1) + factor*some multiple(x3) + something >=x1 && <=x3

        now it will obv not be factor+factor+factor becuase if that

        was the  case then the gcd is already factor


        14, 21 i cant do any better


        it not always better to remove the primes

        because like 13 - >  3,4,6 which leads to 3 gcd

        eg : k==1 and [13,6,8]

        if i remove 13 : 2

        if i remove 6 :

        i think it is better to always remove the smallest elements

        for any arr[i] all the numbers <= arr[i]/4 is definitely

        possible

        for any element i , the numbers that can have this using

        split are 3*i, any number>=4*i else it is i itself :



        can it be done using prefix ?

        for any i to be possible
            suffix of array in sorted order , count of 3*i , count

            of i

*/
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
        sort(arr.begin(), arr.end());
        int maxele = *max_element(arr.begin(), arr.end());
        vector<int> suffix(maxele + 10, 0);
        vector<int> freq(maxele + 10, 0);
        for (int i = 0; i < n; i++)
        {
            suffix[arr[i]]++;
            freq[arr[i]]++;
        }
        int size = suffix.size();
        for (int i = size - 1; i >= 0; i--)
        {
            if (i < size - 1)
                suffix[i] += suffix[i + 1];
        }
        int res = 1; // this is to pakka possible
        for (int currgcd = size - 1; currgcd >= 1; currgcd--)
        {
            // for this to be possible
            int currcount = freq[currgcd];
            // 2* are also  possible

            if ((currgcd * 2) < size)
            {
                currcount += freq[(currgcd * 2)];
            }
            if ((currgcd * 3) < size)
                currcount += freq[(currgcd * 3)];
            if ((currgcd * 4) <= maxele)
            {
                currcount += suffix[(currgcd * 4)];
                // cout << currgcd * 4 << ":" << size << endl;
            }
            int minreq = n - k;

            if (currcount >= minreq)
            {

                res = max(res, currgcd);
                // cout << currgcd << endl;
            }
        }
        cout << res << endl;
    }
    return 0;
}
