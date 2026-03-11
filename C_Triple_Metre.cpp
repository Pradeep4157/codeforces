#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so if first is o then it should be oxxoxx..

    else if first is x then it might be second char or 3rd char..




*/
string temp = "oxx";
bool check(string &s, int start_index)
{
    string res;
    int n = s.size();
    res += temp.substr(start_index);
    while (res.size() < n)
    {
        res += temp;
    }
    for (int i = 0; i < n; i++)
    {
        if (res[i] != s[i])
            return false;
    }

    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    bool res = check(s, 0);
    res |= check(s, 1);
    res |= check(s, 2);
    cout << ((res) ? "Yes" : "No") << endl;
    return 0;
}
