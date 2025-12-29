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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        int i = -1, j = -1;
        for (int k = 0; k < n; k++)
        {
            if (s[k] == '0')
            {
                i = k;
                break;
            }
        }
        for (int k = 0; k < n; k++)
        {
            if (s[k] == '1')
            {
                j = k;
                break;
            }
        }
        if (j == -1)
        {
            cout << 0 << endl;
            continue;
        }
        bool oneturn = 1;
        ll count = 0;

        while (i < n && j < n)
        {
            if (oneturn)
            {
                count++;
                while (i <= j)
                    i++;
                while (i < n && s[i] == '1')
                    i++;
                oneturn = false;
            }
            else
            {
                count++;
                while (j <= i)
                    j++;
                while (j < n && s[j] != '1')
                    j++;
                oneturn = true;
            }
        }
        cout << count << endl;
    }
    return 0;
}
