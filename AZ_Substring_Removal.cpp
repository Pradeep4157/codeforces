#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
            OBSERVATIONS

    abab

    only one ba

    but there are 2 ab..

    so mostly its like first we remove all ba and then rem ab

    and then first all ab and then rem ba..



    bbaab
    ba already rem..

    ab i think i can remove..


    but it should already be removed so some stack sort of approach..

    after all this removall..



*/
int F, S;
int find(string &s, string first, string second, int first_points, int second_points)
{
    int i = 0;
    int n = s.size();
    int res = 0;
    stack<char> st;
    while (i < n)
    {
        if (!st.empty() && s[i] == first[1] && st.top() == first[0])
        {
            st.pop();
            res += first_points;
        }
        else
        {
            st.push(s[i]);
        }
        i++;
    }

    // now all the first's are removed..

    // now in the rem stack we try to find the second string and since it will be in reverse thing we will again find

    // first string only..

    string m;
    while (!st.empty())
    {
        m += st.top();
        st.pop();
    }
    reverse(m.begin(), m.end());
    i = 0;
    while (i < m.size())
    {
        if (!st.empty() && st.top() == second[0] && m[i] == second[1])
        {
            st.pop();
            res += second_points;
        }
        else
        {
            st.push(m[i]);
        }
        i++;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;

        cin >> s >> F >> S;
        int res1 = find(s, "ab", "ba", F, S);

        int res2 = find(s, "ba", "ab", S, F);

        cout << max(res1, res2) << endl;
    }
    return 0;
}
