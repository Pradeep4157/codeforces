#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
map<pair<int, int>, bool> mp;
bool recursion(int a, int b)
{
    if (a < 2 || b < 3)
        return true;
    int temp = a / 2;
    int cf = temp * 2;
    temp = b / 3;
    int cs = temp * 3;

    int second = b - cs;
    int first = a - cf;
    cout << cf << ":" << cs << endl;
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        bool alice_left = 1;
        alice_left = recursion(a - 1, b);

        if (1)
        {
            cout << "Alice" << endl;
        }
        else
            cout << "Bob" << endl;
    }
    return 0;
}
