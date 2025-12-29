#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string res;
        int n = s.size();
        int i = 0;
        while (i < n - 2)
        {

            res += s[i];
            i++;
        }
        res += "i";
        cout << res << endl;
    }
    return 0;
}
