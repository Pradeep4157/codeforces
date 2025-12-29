#include <bits/stdc++.h>
#define int long long
using namespace std;

int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int number = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            number = (number * 10) + (s[i] - '0');
        }
        int root = sqrt(number);
        if ((root * root) != number)
        {
            cout << -1 << endl;
            continue;
        }
        if (number == 0)
            cout << 0 << "  " << 0 << endl;
        else
            cout << 1 << " " << root - 1 << endl;
    }
    return 0;
}
