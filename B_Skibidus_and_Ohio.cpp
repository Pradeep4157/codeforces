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
        int n = s.size();
        bool possible = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (s[i] == s[i - 1])
            {
                possible = 1;
                break;
            }
        }
        if (possible == 0)
        {
            cout << s.size() << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}
