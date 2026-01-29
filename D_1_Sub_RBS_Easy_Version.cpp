#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so s is regular ..

    we need to find a t that is better than s..

    a is better than b when :

        b is prefix of a and a.size() > b.size()...

        this is impossible because  s is literally all that we have and we cannot make t any more bigger..

        2) there is a point where a[i] != b[i] and a[i] == '(' and b[i] == ')'

        we need to find longest of this..


        so at some s it should be something like ((

        so that we make our t like ()

        this maybe can be done using prefix and suffix dp..

        where suffix dp is going to keep len of longest regular bracket subsequence from i..n

        and prefix dp is going to keep len of longest regular bracket subsequence from 0...i

        now we will bf on ) of s we will try to  place ( here..

        so since s is regular there is going to some ( earlier before this..

        so we will place that at this place and we need closing bracket to this index i .. (is it going to be this index of prev index where we

        found opening bracket..)

        mostly it should be prev opening bracket that we thought and the next index is going to be closing only because if next is opening

        then closest will be that only..

        now we are at some place ))) and we need to extend this ..

        we can use suffix of prev_index + 2 and we also need to extend using prefix we will do this by prefix[prev_index - 1]

        suffix in this is correct but is prefix going to ensure that a's opening is on b's closing ?


        

()(())
(())
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
        vector<int> sizes;
        int curr = 0;
        int curr_size = 0;
        for (int i = 0; i < n; i++)
        {
            curr_size++;
            if (s[i] == '(')
                curr++;
            else
                curr--;
            if (curr == 0)
            {
                sizes.push_back(curr_size);
            }
        }
        for (auto a : sizes)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
