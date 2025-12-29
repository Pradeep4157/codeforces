#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int first = -1, last = -1;
    int n = s.size();
    bool found = false;
    long double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 't')
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] == 't' && j - i + 1 >= 3)
                {
                    int count = 0;
                    for (int k = i; k <= j; k++)
                    {
                        if (s[k] == 't')
                            count++;
                    }
                    long double curr = (long double)(count - 2) / (long double)(j - i + 1 - 2);

                    res = max(res, (long double)(count - 2) / (long double)(j - i + 1 - 2));
                }
            }
        }
    }

    cout << fixed << setprecision(17);

    cout << res << endl;

    return 0;
}