#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    i select a zero all ones are converted to zero and all rem zero are conv to one..

    if only one zero then i select that and make all zero..

    else

    the only impossible case is when we have single one..

    for the remaining cases :

        keep taking

    if odd ones and even zeroes then not possible..

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
        int zeroes = 0, ones = 0;
        for (auto a : s)
        {
            if (a == '1')
                ones++;
            else
                zeroes++;
        }
        if (ones == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if ((ones & 1) && (zeroes % 2 == 0))
        {
            cout << -1 << endl;
            continue;
        }
        // now it is possible..
        // when odd zeroes i pick a zero and then ones become zerores - 1
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                mp[0].push_back(i);
            else
                mp[1].push_back(i);
        }
        bool flipped = false;
        // i will start from odd zeroes only..
        bool state = 0;
        vector<int> ans;
        int res = 0;
        if ((ones % 2) == 0)
        {
            // pick a one position..

            for (auto a : mp[1])
                ans.push_back(a);
        }
        else
        {
            for (auto a : mp[0])
            {
                ans.push_back(a);
            }
        }

        // while (true)
        // {
        //     // now if normal case..
        //     if ((flipped && mp[0].empty()) || (flipped == false && mp[1].empty()))
        //         break;
        //     if (flipped)
        //     {
        //         // here ones are zeroes and zeroes are ones..
        //         if (state == 0)
        //         {
        //             // then here 0 is 1. so remove from 1..
        //             ans.push_back(mp[1].back());
        //             mp[1].pop_back();
        //         }
        //         else
        //         {
        //             ans.push_back(mp[0].back());
        //             mp[0].pop_back();
        //         }
        //     }
        //     else
        //     {
        //         // now it is normal array..
        //         // if its' zeroes turn..
        //         if (state == 0)
        //         {
        //             // then there are odd zeroess.
        //             // we take this zero and flip all the ones..
        //             int temp_one = ones;
        //             int temp_zero = zeroes;
        //             ans.push_back(mp[0].back());
        //             mp[0].pop_back();
        //         }
        //         else
        //         {
        //             // we take a one and make odd zeroes..
        //             ans.push_back(mp[1].back());
        //             mp[1].pop_back();
        //         }
        //     }

        //     flipped = (flipped == 1) ? 0 : 1;
        //     state = ((state == 1) ? 0 : 1);
        // }
        cout << ans.size() << endl;
        for (auto a : ans)
            cout << a + 1 << " ";
        cout << endl;
    }
    return 0;
}
