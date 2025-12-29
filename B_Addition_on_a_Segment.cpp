#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    array full of zeroes..

    select a subarray and inc..  all by 1 ..

    array b is given..

    we choose l,r n times..

    and then we can reorder and it should become a..


    what's the max subarray that we choose.

    ok so a -> b ..

    what's the max thing that we choose..

    that will be just the no of non zero elements..

    no because we need to perform n times..

    and each time atleast one needs to be taken..

    so an ele would be inc.. b[i] times..

    1 2 2
    0 0 0
    1 1 1
    1 2 1
    1 2 2

    ok so one of each number..
    apart from zero..

    1 2 2 3
    1 1 1

    ones only one i will choose..

    2 2
    1 1
    2 2
    3 2 2
    1 1 1
    2 2 2
    3 2 2

    1 2 2 2 2 3
    1 1 1 1 1 1


    so when i choose..

    an ele..

    that ele can only contri ele times..

    after that no..

    so 2 can help only one 1

    single 2..

    so every ele can help  ele - 1 elements..

    maybe bs we can do..

    bs on mvoes..

    when is a moves possible ?

    i will select some subarray of that size..

    then keep  selecting only one one..

    i select a subarray of size curr..

    then i should be able to

    then..

    if rem >  0 then imp..

    else poss..

    so when i select a segement of size..

    it is sum of segment + left + right - seg(currsize) - ( n - 1)

    this should be <= 0 ..



    1 1 1 3
    1 1 1 1
    1 1 1 2
    1 1 1 3

    2 2 2
    1 1 1
    2 2 2

    2 can include one 1..

    3 can include


*/
int n;
bool possible(int currsize, int sum)
{

    int res = sum - currsize;

    return (res >= n - 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        int sum = 0;
        int nonzero = 0;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            sum += ele;
            if (ele != 0)
                nonzero++;
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (possible(i, sum))
            {
                res = max(res, i);
            }
        }
        res = min(res, nonzero);
        cout << res << endl;
    }
    return 0;
}
