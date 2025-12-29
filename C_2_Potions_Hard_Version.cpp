#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so 1st thing is obv that i am always going

    to drink all the pos drinks..


    now about the -ve drinks i need

    to be sure that when i drink this..

    my health shouldnt go below 0..

    one more thing is obv that we are

    not going to drink a -ve drink

    if the prefix of pos till this i < arr[i]

    even if the arr[i]<=prefix[i]

    i might skip it ..

    4,-4,-1,-1,-1,-1

    i would rather drink these 4 -1s other

    than 1 -4..

    one more thing..

    i would start drinking from the lowest

    -ve drink..

    because both give 1 point..

    maybe i can bs on these -ve drinks..


    so these -ve drinks must be sorted in

    ascending order on the basis of value

    and descending order on the basis of

    index  because we might be able to drink


    so in the check function i will store

    all these in a map and start calculating

    prefixes..

    and if the index is supposed to be used.

    i will use it && if the sum < 0

    i will return false else i will return true..


    this is wrong because smaller elements

    might be at a place where the prefix is not

    enough to handle this element..

    so this greedy doesnt work..

    if i come from back of the array then

    i can tell things more clearly..

    if i take this arr[i] then what will happen ?

    if i want this arr[i] then first of all

    prefix >=arr[i] ,

    then we can combine this with what..

    i can combine it with some suffix elements.

    whose sum <=arr[i] ..

    so we will start from the end of the array ..

    now we will try to take all the coins

    that we can ..

    also i will keep a sum track of the -ve

    coins that i have taken so far..

    now at some arr[i] which is -ve

    if the prefix[i] -  sum + arr[i] < 0

    then i need to kick out some coins..

    i will kick out the biggest coin..

    and if this coin is bigger than the biggest

    coin..  i will continue..

    there are 2 factors to selecting an element..

    i ) value of arr[i] on how small it is

    ii ) index advantage which it has..

    so there's no greedy way to  solve this


    we need to brute force on a subseq that

    satisfies the condition..

        if we start from 0 .. then what ..

        if i want to take this  arr[i] which is -ve

        then :

            i will try to  merge it with elements such that subsequence

            sum at all the indexes is valid..

            even though an ele is valid at their index it doesnt

            mean that we can merge it with them..

            2,-2,1,-3

            although -2 is valid and -3 is valid but we cant

            merge them together ...

            so maybe  thinking on prefix is only partially correct..

            so if these arr[i] is considered as nodes..

            an edge can only be formed.. when ..

            prefix[u]+dp[u] >=0 &&

            prefix[u] + dp[u] + prefix[v] - prefix[u] + arr[v] >= 0

            or maybe only the 2nd condition is enough..




*/
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> arr(n);
    vector<int> prefix(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= 0)
        {
            prefix[i] = arr[i];
            ans++;
        }
    }
    // prefix proper creation..
    for (int i = 0; i < n; i++)
    {
        if (i)
            prefix[i] += prefix[i - 1];
    }
    int res = ans;

    priority_queue<int, vector<int>, greater<int>> pq;
    int negsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            pq.push(arr[i]);
            negsum += arr[i];
            while (!pq.empty() && prefix[i] + negsum < 0)
            {
                int max = pq.top();
                pq.pop();
                negsum -= max;
            }
        }
    }

    res += pq.size();

    cout << res << endl;

    return 0;
}
