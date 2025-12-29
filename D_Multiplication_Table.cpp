#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    1 2 3 4 5 6 7 ...

    2 4 6 8 .....

    3 6 9 12 15 .....


    1 appears only once ..

    2 appears once ,

    it depends on its factors ..

    like 30 maybe will appear in 1,2,3,5,6,10,15,30

    can we find with factors of n ...


    because it takes root n to find all factors ..

    so we dont need all the factors of n ..

    we iterate from 1... max(n,m) ?

    so we keep maxi = max(n,m) && mini = min(n,m)..

    now we iterate from 1.. maxi ..

    now for every i ..

        it exists in one of its factors ..

        so while finding all the factors of this

        i ...

        we check this ..

        for a currentfactor ..

        for i to exist here ..

            mini >=(i/currentfactor) yes thats true..

            if its true then we do res++

            similarly for n/i as well ..

            after this thing if the currentk >=k

            then we return this i ...

            that should work ... :) HOPE SOO...



            so the values can range more

            than max,min, ...


            so now atleast bf is correct but...

            it gives TLE :(

            only way is BINARY SEARCH :

                i get that for any i if the number of occuring

                elements <=i >=k then we do high = mid - 1

                else low = mid + 1


            but how do we know how many elements<=i have occured

            in the table ?

                yes for this mid to check how many elements <=mid

                we can iterate from row 1... n :

                    and for every row how many numbers are going

                    to be <=mid that is min(mid,m)/row that's it :)


                    this should def work



            1 2
            2 4
            3 6

            1 2 2 3 4 6

*/
int find(int mid, int n, int m)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int curr = (mid) / i;
        curr = min(curr, m);
        res += curr;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int low = 1, high = n * m;
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int curr = find(mid, n, m);

        if (curr >= k)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << res << endl;

    return 0;
}
