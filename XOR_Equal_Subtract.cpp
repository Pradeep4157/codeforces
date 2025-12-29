#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    array is good if all pairs xorr == abs diff of array values..

    max good sunbsequence of array..

    n is small ..

    one way is select all same ele..

    xorr will be 0..

    and subtraction will also be 0..

    else add one other element apart from

    relation is sub and xorr is that if the second ele..

    is a submask of the first ele..

    then sub all the bits of second ele will be removed..

    and  in xorr also second ele bits will be removed..

    so i will brute force from largest to smallest and for each

    ele if the current ele is submask of all the ele considered

    then i might take or skip..

    will i skip ?


    i wont skip..

    i wont consider always..

    i might skip ..

    maybe the current ele should be submask of the min ele found so far..

    then only we will consider..

    we might skip as well..

*/
map<pair<int, int>, int> dp;
int n;
int recursion(int start, vector<int> &arr, int curr)
{
    if (start == n)
    {
        return 0;
    }
    // i will skip..
    if (dp.find({start, curr}) != dp.end())
        return dp[{start, curr}];
    int res = recursion(start + 1, arr, curr);

    // i might take..
    if (curr == 0 || ((arr[start] ^ curr) == abs(arr[start] - curr)))
    {
        int new_xorr = ((curr == 0) ? arr[start] : min(arr[start], curr));

        res = max(res, 1 + recursion(start + 1, arr, new_xorr));
    }

    return dp[{start, curr}] = res;
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
        vector<int> arr(n);
        dp.clear();
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int res = 1;
        sort(arr.rbegin(), arr.rend());
        cout << recursion(0, arr, 0) << endl;
    }
    return 0;
}
