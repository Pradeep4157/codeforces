#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int middle = (s.size()) / 2;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == middle)
            continue;
        cout << s[i];
    }
    cout << endl;
    return 0;
}
