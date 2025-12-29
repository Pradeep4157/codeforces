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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int firstmin = min(a, c);
        int secondmin = min(b, d);
        if (firstmin < secondmin)
            cout << "Flower" << endl;
        else
            cout << "Gellyfish" << endl;
    }
    return 0;
}
