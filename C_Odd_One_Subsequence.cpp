#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for every j i can use all i before it that are equal to it and all k after that

    which are not equal to this arr[j]

    but this ensures that i,j are equal and k is always unequal what about

    j,k equal and i unequal  and also i and k can be equal

    else if i fix i , what all values can be there :
        i and j equal or equal  to k :
            all the values that are not equal to the right of i

            here there is a case that there should be some element after i

        now for j == k :
            2 3 4 3 4 3

            2 3 3
            2 3 3
            2 3 3
            2 4 4

            for this sum of same elements count c 2

            or for this i can another traversal with j :

            for that :
                for all j 's i can combine with all k's == j :
                    multiplied by all i's not equal  to  j
*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]].push_back(i);
    }
    int res = 0;
    // this is for j && k equal
    for (int j = 1; j < n - 1; j++)
    {
        vector<int> &indexes = mp[arr[j]];
        auto it = lower_bound(indexes.begin(), indexes.end(), j);
        // now it is pointing at j

        int size = indexes.size();
        int ae = 0, bue = 0;
        int beforesame = it - indexes.begin();
        int aftersame = size - (beforesame)-1;
        bue = j - beforesame;
        ae = aftersame;
        res += (bue * ae);
    }
    // now for i == j or i == k
    for (int i = 0; i < n; i++)
    {
        vector<int> &indexes = mp[arr[i]];
        int size = indexes.size();
        if (indexes[size - 1] != i)
        {
            // this shouldnt be the last index
            // then we can match with j && k
            auto it = lower_bound(indexes.begin(), indexes.end(), i);

            int beforesame = it - indexes.begin();
            int aftersame = size - (beforesame)-1;
            int afternotsame = n - i - 1 - aftersame;
            res += (afternotsame * aftersame);
        }
    }
    cout << res << endl;
    return 0;
}
