#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; ++i)
            cin >> l[i];
        for (int i = 0; i < n; ++i)
            cin >> r[i];

        vector<int> extra;
        long long result = 0;
        for (int i = 0; i < n; ++i)
        {
            result += max(l[i], r[i]);
            extra.push_back(min(l[i], r[i]));
        }
        sort(extra.rbegin(), extra.rend());
        for (int i = 0; i < k - 1; ++i)
            result += extra[i];
        result += 1;
        cout << result << '\n';
    }
    return 0;
}
