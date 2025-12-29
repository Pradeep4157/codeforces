#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == "fine" && s2 == "fine")
    {
        cout << 4 << endl;
    }
    else if (s1 == "sick" && s2 == "sick")
    {
        cout << 1 << endl;
    }
    else if (s1 == "sick")
    {
        cout << 2 << endl;
    }
    else
        cout << 3 << endl;
    return 0;
}
