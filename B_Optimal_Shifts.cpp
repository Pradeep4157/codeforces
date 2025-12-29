#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    bs ..

    at least one one..

    convert it to all ones..

    so choose d do right shift of last d chars. .

    andd then wherever there is 1 in this right shifted string

    make s indexes also 1..

    costs d..

    min coins to do this..

    for an index i in s..

    if i want to change..

    i will  have to put 1 in that index..

    this is def..

    after every op we are having new strings so maybe there is

    a possibility that this index might have already become 1 in

    the process of some prev 0->1..


    subarray thing where to make current zero subarray === 1

    i will choose left subarray of ones..

    now after an op ..

    next subarrays of size <= current subarray are also already one..


    i need to merge last zero subarray with the first zero subarray..





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
        string s;
        cin >> s;
        vector<pair<int, int>> zeroes;
        int i = 0;
        while (i < n)
        {
            while (i < n && s[i] == '1')
                i++;
            if (i == n)
                break;
            int j = i;
            while (j < n && s[j] == s[i])
                j++;
            j--;
            zeroes.push_back({i, j});
            i = j + 1;
        }
        int size = zeroes.size();
        // merge last zeroes with first zeroes..
        int res = 0;
        if (s[0] == '0' && s[n - 1] == '0')
        {
            // then we might merge..
            // unless they are already merged..
            // if already same..
            if (zeroes[0].first == 0 && zeroes[0].second == n - 1)
            {
                // then no merge..
            }
            else
            {
                // we merge here.

                res = n - zeroes[size - 1].first + zeroes[0].second + 1;
            }
        }
        // now we consider all the other subarrays..
        for (auto a : zeroes)
        {
            res = max(res, a.second - a.first + 1);
        }
        cout << res << endl;
    }
    return 0;
}
