#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    bool can = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            if (can)
            {
                can = false;
                s[i] = 'o';
            }
        }
        else if (s[i] == '#')
        {
            if (can == false)
                can = true;
        }
    }
    cout << s << endl;
    return 0;
}
