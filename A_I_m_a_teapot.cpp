#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n >= 3 && s.substr(n - 3, 3) == "tea")
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}
