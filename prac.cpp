#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    'A' to Z is assigned 1..26

    100
*/
int find(string s)
{
    if (s.size() == 0)
    {
        return 1;
    }
    char first = s[0];
    int res = 0;
    int FIRST;
    FIRST = first - '0';
    cout << FIRST << endl;
    if (first > '0')
    {
        string rem = s.substr(1);
        res += 1 * find(rem);
    }
    if (s.size() > 1)
    {
        string first_two = s.substr(0, 2);
        int first_Two = stoi(first_two);
        if (first_Two > 0 && first_Two < 27 && FIRST != first_Two)
        {
            res += find(s.substr(2));
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    cin >> n;
    int res = find(n);
    if (res > 0)
    {
        cout << res << endl;
    }
    return 0;
}
