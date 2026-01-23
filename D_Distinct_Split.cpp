#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    we can mostly bf on the right pointer..

    since the chars are 26 only..

    so first store all the chars

    in the freq array and then for every right

    pointer if the current char is not seen

    yet then a++

    and remove it from freq array and if

    it become zero then b--;

    b is initially the diff chars in freq array..


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
        vector<int> freq(26, 0);
        int b = 0;
        // first finding b ..
        for (int i = 0; i < n; i++)
        {
            int index = s[i] - 'a';
            freq[index]++;
            if (freq[index] == 1)
            {
                b++;
            }
        }
        int a = 0;
        int res = 0;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int index = s[i] - 'a';
            freq[index]--;
            if (freq[index] == 0)
            {
                b--;
            }
            if (!st.count(index))
            {
                a++;
            }
            st.insert(index);
            res = max(res, a + b);
        }
        cout << res << endl;
    }
    return 0;
}