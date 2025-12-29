#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


        bob only wins till the string is empty &&

        alice wins as soon as she makes them equal

        && one more thing that is true is that abs(01,10) will

        always be 1

        so the only way that bob wins is that if either 10 is

        0 or 01 is 0 or both are 0

        so if any count is 0 return bob else return alice

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
        int zo = 0, oz = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0' && s[i + 1] == '1')
                zo++;
            else if (s[i] == '1' && s[i + 1] == '0')
                oz++;
        }
        if (zo == 0 || oz == 0)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    return 0;
}
