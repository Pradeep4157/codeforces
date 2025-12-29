#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    ll n = s.size();
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != 'A')
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] != 'B')
                continue;
            int dist = j - i;
            if (j + dist < n && s[j + dist] == 'C')
                res++;
        }
    }
    cout << res << endl;
    return 0;
}
