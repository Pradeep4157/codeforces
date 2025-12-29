#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        string p;
        cin >> p;
        string s;
        cin >> s;
        int n = p.size(), m = s.size();
        int left1 = 0, left2 = 0;
        bool possible = true;
        while (left1 < n || left2 < m)
        {
            if (p[left1] != s[left2])
            {

                possible = false;
                break;
            }

            int right1 = left1;
            while (right1 < n && p[right1] == p[left1])
                right1++;
            right1--;
            int beats = right1 - left1 + 1;
            int right2 = left2;
            while (right2 < m && s[right2] == s[left2] && right2 - left2 + 1 <= 2 * beats)
                right2++;
            right2--;
            int sounds = right2 - left2 + 1;
            if (sounds > 2 * beats || sounds < beats)
            {

                possible = false;
                break;
            }
            left1 = right1 + 1;
            left2 = right2 + 1;
        }
        if ((left1 == n && left2 != m) || (left1 != n && left2 == m))
        {
            possible = false;
        }
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
