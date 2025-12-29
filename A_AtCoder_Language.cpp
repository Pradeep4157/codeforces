#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (s == "red")
        cout << "SSS" << endl;
    else if (s == "blue")
        cout << "FFF" << endl;
    else if (s == "green")
        cout << "MMM" << endl;
    else
        cout << "Unknown" << endl;
    return 0;
}
