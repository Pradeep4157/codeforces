#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so for every si either si == ti

    or si == si - 1 or si == ti - 1

    because only these 3 values are possible ..

    if si == si - 1 i can push the current string now only and then process from i - 1

    else if si == ti  continue with  i - 1

    else if si == ti - 1 :

        first process i - 1

        then push this changed value
*/
vector<string> res;
int n, k;

bool recursion(int i, string s, int kleft, string &t)
{
    if (i == 0)
    {
        if (s[i] == t[i])
            return 1;
        else
            return 0;
    }
    // now intermediate indexes..
    if (s[i] == t[i])
    {
        return recursion(i - 1, s, kleft, t);
    }
    else
    {
        if (kleft == 0)
            return 0;
        kleft--;
        bool ans;
        if (s[i] == s[i - 1])
        {
            s[i] = s[i - 1];
            res.push_back(s);
            ans = recursion(i - 1, s, kleft, t);
            return ans;
        }
        else if (s[i] == t[i - 1])
        {
            ans = recursion(i - 1, s, kleft, t);
            res.push_back(s);
            return ans;
        }
        else
        {
            // not equal to s[i-1] && t[i-1] we cant do anything..
            return 0;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string t;
        cin >> t;
        cout << s << ":" << t << endl;
        bool possible = recursion(n - 1, s, k, t);
        if (possible == false)
            return -1;
        cout << res.size() << endl;
        for (auto a : res)
            cout << a << endl;
    }
    return 0;
}
