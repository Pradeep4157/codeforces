#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    string curr;
    cin >> curr;

    if (curr == "Ocelot")
    {
        a = 1;
    }
    else if (curr == "Serval")
    {
        a = 2;
    }
    else
    {
        a = 3;
    }
    cin >> curr;

    if (curr == "Ocelot")
        b = 1;
    else if (curr == "Serval")
        b = 2;
    else
        b = 3;

    if (b <= a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
