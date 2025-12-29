#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (400 % n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << 400 / n << endl;
    }
    return 0;
}
