#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for an a i can take b and c on right..

    its like for B i need to find left a and right c

    that's it ?





*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    deque<int> q;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'C')
            q.push_front(i);
    }

    vector<int> a;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'C')
        {
            // either it has been removed from the b before
            // or it is here..
            while (!q.empty())
            {
                int first = q.front();
                if (first <= i)
                    q.pop_front();
                else
                    break;
            }
            // now everything till here is removed..
        }
        else if (s[i] == 'A')
        {
            a.push_back(i);
        }
        else
        {
            // maybe i can
            if ((!a.empty()) && (!q.empty()))
            {

                q.pop_front();
                a.pop_back();
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
