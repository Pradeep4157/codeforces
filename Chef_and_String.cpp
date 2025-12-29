#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so A is just K times S. ..

    now score is indices where ai= ai + 1 ..

    so there is fixed.. score..

    in s if any si = si + 1 .. just do  res+=(k)

    and if last char == first char then do res += k-1

    now for normal chars and si chars..

    the only problem is when first subsarray and last is I ..

    here we need to decide whether to make I equal to char

    ahead of first / char before last..

    if both are same..

    then do res+=(2*k)

    else do res+=k

    when first and last are I only then if i make them same..

    then

    when the size > 1 if they are not at the end at starting..
    then they still can have 2*k


    for every I substring if the char before and char after is same..

    then we can have 2*k more..

    else we can only have +k more ..


    now for the substring that is at tne end or the beginning of s..

    if the char before them and after is same then we get ..

    + k + k + k - 1

    else we get + k + k



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
        string s;
        cin >> s;
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
                res += k;
        }
        // if they can be equal then make them.. unless its I
        if (s[0] == s[n - 1] && s[n - 1] != 'I')
            res += (k - 1);

        // now for the subset thing..
        vector<pair<int, int>> arr;
        int i = 0;
        while (i < n)
        {
            while (i < n && s[i] != 'I')
                i++;
            if (i == n)
                break;
            int j = i;
            while (j < n && s[j] == s[i])
                j++;
            j--;
            arr.push_back({i, j});
            i = j + 1;
        }

        if (arr.size() > 1)

        {
            int size = arr.size();

            for (int i = 0; i < size; i++)
            {
                if (arr[i].first != 0 && arr[i].second != n - 1)
                {
                    char before = s[arr[i].first - 1];
                    char after = s[arr[i].second + 1];
                    if (before == after)
                    {
                        res += (2LL * k);
                    }
                    else
                        res += k;
                }
            }
            // we will make all first I's equal to char after I ..
            if (arr[0].first == 0)
                res += k;

            // we will make all end I's equal to char before them..
            if (arr[size - 1].second == n - 1)
                res += k;
            // now here is the chance where we make last I 's equal to first I 's and get some more same's..
            if (arr[0].first == 0 && arr[size - 1].second == n - 1)
            {

                char before = s[arr[size - 1].first - 1];
                char after = s[arr[0].second + 1];
                if (before == after)
                    res += (k - 1);
            }
            else if (arr[0].first == 0)
            {
                // then also there's a chance char after and last is same...
                char after = s[arr[0].second + 1];
                if (s[n - 1] == after)
                    res += k - 1;
            }
            else if (arr[size - 1].second == n - 1)
            {
                char before = s[arr[size - 1].first - 1];
                if (s[0] == before)
                    res += k - 1;
            }
        }
        if (arr.size() == 1)
        {
            if ((arr[0].second - arr[0].first + 1) < n)
            {

                if (arr[0].second == n - 1 || (arr[0].first == 0))
                {
                    char before, after;
                    if (arr[0].first == 0)
                        before = s[n - 1];
                    else
                        before = s[arr[0].first - 1];
                    if (arr[0].second == n - 1)
                        after = s[0];
                    else
                        after = s[arr[0].second + 1];

                    // then before == after..
                    res += k; // for before..
                    if (before == after)
                        res += (k - 1); // for I
                }
                else
                {
                    // now before and after must be equal..
                    char after = s[arr[0].second + 1];
                    char before = s[arr[0].first - 1];
                    if (after == before)
                        res += 2LL * k;
                    else
                        res += k;
                }
            }
            else if (arr[0].first == 0 && arr[0].second == n - 1)
                res += (k - 1);
        }
        cout << res << endl;
    }
    return 0;
}
