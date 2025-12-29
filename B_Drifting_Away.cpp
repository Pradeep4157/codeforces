#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so the inf glitch is that

    there should be an  * cell


    along with either left cell >

    or right cell with <

    or there are two * cells..

    or cell like this ..

    so 3 cases..

    else

        the config will be something..

        like this..

        <<<<<<*>>>>>>>
*/
bool isinf(char s, char t)
{
    return ((s == '>' && t == '<') || (s == '>' && t == '*') || (s == '*' && t == '<') || (s == '*' && t == '*'));
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
        cin >> s;
        int n = s.size();
        bool inf = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (isinf(s[i], s[i + 1]))
                inf = 1;
        }
        if (inf)
        {
            cout << -1 << endl;
        }

        else
        {
            int left = 0, right = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '>')
                    break;
                left++;
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '<')
                    break;
                right++;
            }
            cout << max(left, right) << endl;
        }
    }
    return 0;
}
