#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


        so there are subarrays..


        for 1 subarrays changing

        odd is always better..

        for 0 ?

        1212
        01010

        for 1 subarrays we will always

        change odd indexes..


        for 0 subarrays..

            if it is odd then again we

            will just add size / 2

            else :

                if the prev or next one

                subarray

    the only problem is the adjacent

    even zero subarrays..

    for these adj even zero subarrays..

    if the left side of this subarray there

    is 1 subarray and right of the next subarray

    is also 1 subarray..

    then we need to add 1 to the res..

    one more case is if the left subarray

    has left zero


    ok so by default i will always


    try to change the odd indexes..


    0101111101021111

    101012120101

    11111010121210000

    for zero subarrays if it is odd we

    dont care..

    else if it even.. if it's left is 0

    or right is n - 1 then also we dont

    care.

    121211010




*/
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }
    return 0;
}
